#include <iostream>//cout<<right で右揃え
#include <iomanip>//cout<<setw(数字) で空白による桁揃え
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdlib>//abs()で整数絶対値
#include <cmath>//abs()かfabs()で少数絶対値
#include <functional>//sort第三引数greater<型名>()で降順
#include <map>

using namespace std;
using ll = long long int;

int main(){
    int K;cin>>K;
    vector<int> A(K+1);
    A[1] = 7 % K;
    for(int i=2;i<=K;i++) A[i] = (A[i-1]*10 + 7) % K;
    for(int i=1;i<=K;i++){
        if(A[i]==0){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
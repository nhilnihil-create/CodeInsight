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
    int N;cin>>N;
    vector<pair<int,int>> A(N);
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        A[i] = {b,a};
    }
    sort(A.begin(),A.end());
    int time = 0;
    for(int i=0;i<N;i++){
        time += A[i].second;
        if(time > A[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
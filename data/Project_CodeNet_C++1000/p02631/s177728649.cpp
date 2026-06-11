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
    int all = 0;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        all = all^A[i];
    }
    for(int i=0;i<N;i++){
        int ans;
        ans = all^A[i];
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}
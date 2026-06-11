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
    vector<int> A(N);
    map<int,int> m;
    int max = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        m[A[i]]++;
        if(A[i]>max) max = A[i];
    }
    vector<bool> dp(max+1,true);
    for(int i=0;i<N;i++){
        if(dp[A[i]]){
            for(int j=2;j*A[i]<=max;j++){
                dp[j*A[i]] = false;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        if(dp[A[i]]&&m[A[i]]==1) ans++;
    }
    cout << ans << endl;
    return 0;
}
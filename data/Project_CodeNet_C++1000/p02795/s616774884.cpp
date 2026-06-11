#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<list>

#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)

int main(){
    int h,w,n;
    cin>>h>>w>>n;
    int ans = 0,black = 0;
    for(int i=0;i<min(h,w);i++){
        black += max(h,w);
        ans++;
        if(black >= n) break;
    }
    cout<<ans<<endl;
}
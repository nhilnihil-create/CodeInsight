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
    int ans = (n+max(h,w)-1) / max(h,w);
    cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 200000;
ll mod = INF;


int main(){
    map<string,int> m; 
    int n;
    int M=0;
    cin >> n;
    rep(i,n){
        string s;
        cin >> s;
        m[s]++;
        M=max(M,m[s]);
    }

    vector<string> ans;
    for(auto ite=m.begin();ite!=m.end();ite++){
        if(M==ite->second){
            ans.push_back(ite->first);
        }
    }

    sort(ans.begin(),ans.end());
    rep(i,ans.size())cout << ans[i]<<endl;
    return 0;
}
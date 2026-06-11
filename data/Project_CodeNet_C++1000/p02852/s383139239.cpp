#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;
const ll mod=998244353;

int main(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    multiset<pair<int,int>> minimum;
    vin dp(n+1,inf),before(n+1,inf);dp[0]=0;
    rep2(i,1,min(n,m)+1){
        if(s[i]=='0'){
            dp[i]=1;
            before[i]=0;
        }
        minimum.insert(mp(dp[i],i));
    }
    int tmp;
    rep2(i,m+1,n+1){
        if(s[i]=='0'){
            tmp=(*minimum.begin()).first;
            if(tmp!=inf)tmp++;
            dp[i]=tmp;
            before[i]=(*minimum.begin()).second;
        }
        minimum.erase(minimum.find(mp(dp[i-m],i-m)));
        minimum.insert(mp(dp[i],i));
    }
    if(dp[n]==inf){
        cout<<-1<<endl;
        return 0;
    }
    stack<int> ans;
    tmp=n;
    while(tmp){
        ans.push(tmp-before[tmp]);
        tmp=before[tmp];
    }
    while(ans.size()>1){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<ans.top()<<endl;
}
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
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int n;cin>>n;
    int s=to_string(n).size();
    if(s==1){
        cout<<n<<endl;
        return 0;
    }
    vvll num(10,vll(10));//num[i][j]:iで始まってjで終わるn以下の数の数
    ll res;
    rep2(i,1,10)rep2(j,1,10){
        res=1;
        rep2(k,2,s){
            num[i][j]+=res;
            res*=10;
        }
        if(i<n/(10*res))num[i][j]+=res;
        else if(i==n/(10*res)){
            num[i][j]+=(n%(10*res))/10;
            if(j<=n%10)num[i][j]++;
        }
        if(i==j)num[i][j]++;
    }
    ll ans=0;
    rep2(i,1,10)rep2(j,1,10)ans+=num[i][j]*num[j][i];
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 2
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

int n;
//mCiを見る
bool f(vector<int> v){
    int m=n-1;
    vector<int> sum(m+2,0);
    for(int i=1;i<=m;i++){
        sum[i+1]=sum[i]+__builtin_ffs(i)-1;
    }
    int ret=0;
    for(int i=0;i<=m;i++){
        int si=sum[m+1]-sum[m+1-i];
        int bo=sum[i+1];
        if(si-bo==0) ret+=v[i]; 
    }    
    return ret%2;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin>>n;
    string s;cin>>s;

    rep(i,s.size()){
        if(s[i]=='1') s[i]='0';
        else if(s[i]=='2') s[i]='1';
        else if(s[i]=='3') s[i]='2';
    }
    int cnt[3]={};
    rep(i,s.size()){
        cnt[s[i]-'0']++;
    }
    int cntcnt=0;rep(i,3)if(cnt[i]>0) cntcnt++;
    if(cntcnt==1){
        cout<<0<<endl;
        return 0;
    }
    if(cnt[1]==0){
        vector<int> v(n);
        rep(i,n){
            if(s[i]=='0')   v[i]=0;
            else            v[i]=1;
        }
        if(f(v)) cout<<2<<endl;
        else     cout<<0<<endl;
        return 0;
    }

    vector<int> v(n);
    rep(i,n){
        if(s[i]=='1') v[i]=1;
        else          v[i]=0;
    }
    if(f(v))    cout<<1<<endl;
    else        cout<<0<<endl;
    return 0;
}

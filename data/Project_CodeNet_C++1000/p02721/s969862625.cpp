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

int main(){
    int n,k,c;cin>>n>>k>>c;
    string s;cin>>s;
    vin l(n),r(n);
    int res=0,cnt=1;
    while(res<n&&cnt<=k){
        if(s[res]=='o'){
            l[res]=cnt;
            cnt++;
            res+=c;
        }
        res++;
    }
    res=n-1;cnt=k;
    while(res>=0&&cnt>0){
        if(s[res]=='o'){
            r[res]=cnt;
            cnt--;
            res-=c;
        }
        res--;
    }
    rep(i,n)if(s[i]=='o'&&l[i]!=0&&r[i]!=0&&l[i]==r[i])cout<<i+1<<endl;
}
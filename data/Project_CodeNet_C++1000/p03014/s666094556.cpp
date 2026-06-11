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
    int h,w;cin>>h>>w;
    vstr s(h);rep(i,h)cin>>s[i];
    vvin lineleft(h,vin(w)),lineright(h,vin(w)),rowup(w,vin(h)),rowdown(w,vin(h));
    int tmpll,tmplr,tmpru,tmprd;
    rep(i,h){
        tmpll=-1;tmplr=w;
        rep(j,w){
            if(s[i][j]=='#'){
                lineleft[i][j]=j;
                tmpll=j;
            }
            else lineleft[i][j]=tmpll;
            if(s[i][w-1-j]=='#'){
                lineright[i][w-1-j]=w-1-j;
                tmplr=w-1-j;
            }
            else lineright[i][w-1-j]=tmplr;
        }
    }
    rep(i,w){
        tmpru=-1;tmprd=h;
        rep(j,h){
            if(s[j][i]=='#'){
                rowup[i][j]=j;
                tmpru=j;
            }
            else rowup[i][j]=tmpru;
            if(s[h-1-j][i]=='#'){
                rowdown[i][h-1-j]=h-1-j;
                tmprd=h-1-j;
            }
            else rowdown[i][h-1-j]=tmprd;
        }
    }
    int ans=0;int tmp;
    rep(i,h)rep(j,w){
        if(s[i][j]!='#'){
            tmp=(lineright[i][j]-lineleft[i][j]-1)+(rowdown[j][i]-rowup[j][i]-1)-1;
            ans=max(ans,tmp);
        }
    }
    cout<<ans<<endl;
}
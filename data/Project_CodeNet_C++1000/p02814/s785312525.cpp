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

ll lcd(ll x,ll y){
    return x*y/__gcd(x,y);
}

int main(){
    int n;ll m;cin>>n>>m;
    vin a(n);
    cin>>a[0];a[0]/=2;
    int tmp=a[0];int res=0;
    while(tmp%2==0){
        tmp/=2;
        res++;
    }
    bool twonum=true;int tmp2,res2;
    rep2(i,1,n){
        cin>>a[i];a[i]/=2;
        if(twonum){
            tmp2=a[i];res2=0;
            while(tmp2%2==0){
                tmp2/=2;
                res2++;
            }
            if(res2!=res)twonum=false;
        }
    }
    if(!twonum){
        cout<<0<<endl;
        return 0;
    }
    ll l=(ll)a[0];
    rep2(i,1,n){
        l=lcd(l,(ll)a[i]);
        if(l>m){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<(m+l)/(2*l)<<endl;
}
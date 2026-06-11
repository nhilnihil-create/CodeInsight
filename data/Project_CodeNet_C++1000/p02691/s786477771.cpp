#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pnn=pair<int ,int>;

#define ft first
#define sd second
#define fn front
#define pb push_back
#define it insert
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sot(x) sort(x.begin(), x.end())
#define rese(x) reverse(x.begin(), x.end())
#define vnn(x,y,s,name) vector<vector<int>> name(x, vector<int>(y,s))
#define mse(x) memset(x, 0, sizeof(x))
#define mii(x,y,z) min(x,min(y,z))
#define maa(x,y,z) max(x,max(y,z))

string yes="Yes",no="No";

int main() {
    int n;
    cin>>n;
    vin a(n),asum(n),ami(n);
    rep(i,n){
        cin>>a[i];
        asum[i]=i+a[i];
        ami[i]=i-a[i];
    }
    
    ll ans=0;
    Graph ascnt(n),amcnt(n);
    map<int ,int> asac,amac;
    set<int> st;
    rep(i,n){
        if(asac.count(asum[i])){
            ascnt[asac[asum[i]]].pb(i);
        }
        else{
            asac[asum[i]]=i;
            ascnt[i].pb(i);
            st.insert(i);
        }
        if(amac.count(ami[i])){
            amcnt[amac[ami[i]]].pb(i);
        }
        else{
            amac[ami[i]]=i;
            amcnt[i].pb(i);
        }
    }
    
    for(int i:st){
        int j=asum[i];
        
        if(!amac.count(j)) continue;
        int h=ascnt[i].size();
        vin mio(h,0);
        for(int x: amcnt[amac[j]]){
            int ng=-1,ok=h;
            while(ok-ng>1){
                int mid=(ok+ng)/2;
                if(ascnt[i][mid]<x) ok=mid;
                else ng=mid;
            }
            if(ok==h) continue;
            ans+=(h-ok);
        }
    }
    cout<<ans<<endl;
}

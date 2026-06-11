#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

string yes="Yes",no="No";

int main() {
    int h,w,m;
    cin>>h>>w>>m;
    set<pinin> s;
    vin hm(h),wm(w);
    rep(i,m){
        pinin hw;
        cin>>hw.first>>hw.second;
        hw.first--; hw.second--;
        s.insert(hw);
        hm[hw.first]++;
        wm[hw.second]++;
    }
    set<int> hma,wma;
    int hmax=0,wmax=0;
    rep(i,h){
        hmax=max(hmax,hm[i]);
    }
    rep(i,w){
        wmax=max(wmax,wm[i]);
    }
    rep(i,h){
        if(hmax==hm[i]) hma.insert(i);
    }
    rep(i,w){
        if(wmax==wm[i]) wma.insert(i);
    }
    int ans=hmax+wmax-1;
    bool fin=false;
    for(int x:hma){
        for(int y:wma){
            pinin xy;
            xy.first=x;
            xy.second=y;
            if(!s.count(xy)){
                ans=hmax+wmax;
                break;
                fin=true;
            }
        }
        if(fin) break;
    }
    cout<<ans<<endl;
  

}

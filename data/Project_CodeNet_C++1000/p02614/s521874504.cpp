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
#define si(v) int((v).size())
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
    int h,w,k;
    cin>>h>>w>>k;
    vector<string> fie(h);
    rep(i,h) cin>>fie[i];
    
    int ans=0;
    
    int h2=pow(2,h),w2=pow(2,w);
    //int h3=64/h2,w3=64/w2;
   // cout<<h2<<" "<<w2<<endl;
    for(int i=0;i<h2;i++){
        for(int j=0;j<w2;j++){
            int cnt=0;
            bitset<6> s(i);
            bitset<6> t(j);
            
            rep(l,h){
                rep(r,w){
                    if(s[l]==1||t[r]==1) continue;
                    if(fie[l][r]!='#') continue;
                    cnt++;
                }
            }
            if(cnt==k) ans++;
            //cout<<cnt<<endl;
        }
    }
    cout<<ans<<endl;
    
   
   
}

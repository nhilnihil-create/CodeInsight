#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
string alp="abcdefghijklmnopqrstuvwxyz";
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int main(){
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    if(n%3!=0){
        rep(i,0,n-1){
            if(a[i]!=0){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
    }else{
        
        unordered_map<ll,ll> mp;
        vector<ll> num;
        rep(i,0,n-1){
            if(mp.find(a[i])==mp.end()){
                num.pb(a[i]);
                mp[a[i]]=1;
                if(num.size()>3){
                    cout<<"No"<<endl;
                    return 0;
                }
            }else{
                mp[a[i]]++;
            }
        }
        if(num.size()==1){
            if(num[0]==0){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else if(num.size()==2){
            if(mp[num[0]]==n/3 && mp[num[1]]==2*n/3){
                if(num[0]==0){
                    cout<<"Yes"<<endl;
                }else{
                    cout<<"No"<<endl;
                }
            }else if(mp[num[1]]==n/3 && mp[num[0]]==2*n/3){
                if(num[1]==0){
                    cout<<"Yes"<<endl;
                }else{
                    cout<<"No"<<endl;
                }
            }else{
                cout<<"No"<<endl;
            }
        }else if(num.size()==3){
            if(mp[num[0]]==n/3 && mp[num[1]]==n/3 && mp[num[2]]==n/3){
                if((num[0]^num[1])==num[2]){
                    cout<<"Yes"<<endl;
                }else{
                    cout<<"No"<<endl;
                }
            }else{
                cout<<"No"<<endl;
            }
        }else{
            cout<<"No"<<endl;
        }
    }
    
    
    return 0;
}





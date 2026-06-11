#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<ll> a(n+1,0);
    rep(i,n+1) cin>>a[i];
    vector<ll> b(n+3,1);
    ll maxi=1;
    rep(i,n+1){
        maxi-=a[i];
        if((maxi==0&&i!=n)||maxi<0){
            cout<<-1<<endl;
            return 0;
        }
        if(maxi*2<=1e+18)maxi*=2;
        b[i+1]=maxi;
    }
    
    ll tmp=-1,res=0;
    rep(i,n+1){
        if(i==0){
            tmp=a[n];
            if(tmp>b[n]){
                cout<<-1<<endl;
                return 0;
            }
            res+=tmp;
            //cout<<i<<" "<<tmp<<endl;
            continue;
        }
        if(tmp>b[n-i]*2){
            cout<<-1<<endl;
            return 0;
        }else if(tmp+a[n-i]>=b[n-i]){
            tmp=b[n-i];
        }else{
            tmp+=a[n-i];
        }
        res+=tmp;
        //cout<<i<<" "<<tmp<<endl;
    }
    cout<<res<<endl;
    return 0;
}
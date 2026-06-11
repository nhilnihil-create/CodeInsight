#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    int v,p;
    cin>>v>>p;
    p = n-p;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    //rep(i,n)cout<<a[i];cout<<endl;
    ll ok=n-1;
    ll ng=-1;
    while(1<abs(ok-ng)){
        int mi=(ok+ng)/2;
        //cout<<mi<<endl;
        if (mi>=p){
            ok=mi;
        }
        else if(p>mi){
            if(a[mi]+m<a[p]){
                ng=mi;
            }
            else{
                ll cnt=abs(p-mi);
                if(v<=n-cnt){
                    //cout<<mi<<" "<<cnt<<" "<<ng<<endl;
                    ok=mi;
                }
                else{
                    ll res = 0;
                    REP(j,mi+1,p+1){
                        res+=a[mi]+m-a[j];
                    }
                    if(res+(n-cnt)*m>=v*m){
                        ok=mi;
                    }
                    else{
                        ng=mi;
                    }
                }
            }
        }
    }
    cout<<n-ok<<endl;
}
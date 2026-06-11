#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
long double eps = 1e-6;
long double pi = acos(-1);




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);


    ll n;
    cin>>n;
    ll ans = 0;
    n--;
    // 1 kai mo kakenai
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            if(i!=1) ans++;
            if(i*i!=n)ans++;
        }
    }
    n++;
    for(ll k=1;k*k<=n;k++){
        if(n%k==0){
            ll a = k, b = n/k;
            ll tmp = n;
            if(a!=1){
                while(tmp%a==0) tmp/=a;
                tmp--;
                if(tmp%a==0)ans++;
            }
            if(a==b)continue;
            tmp = n;
            while(tmp%b==0)tmp/=b;
            tmp--;
            if(tmp%b==0)ans++;
        }
    }
    cout << ans << endl;
}
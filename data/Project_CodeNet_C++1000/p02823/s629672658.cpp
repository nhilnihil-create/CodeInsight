#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1LL<<60
#define pi 3.14159265358979323846
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    ll n,a,b,ans=0;cin>>n>>a>>b;

    if((b-a)%2==0){ans=(b-a)/2;}
    else{
        if(n-b<a-1){
            ans+=(n-b);
            a+=(n-b);
            ans++;
            a++;
            ans+=(n-a)/2;
        }else{
            ans+=(a-1);
            b-=(a-1);
            ans++;
            b--;
            ans+=(b-1)/2;
        }
    }

    cout<<ans<<endl;
    return 0;
}
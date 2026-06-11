#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;

ll GCD(ll a,ll b){
    return b?GCD(b,a%b):a;
}
ll LCM(ll a,ll b){
    if(a==0)return b;
    if(b==0)return a;
    return a/GCD(a,b)*b;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    int a[n];
    int fl=0,l=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        fl=LCM(fl,a[i]/2);
        l=LCM(l,a[i]);
    }
    if(fl>m){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        if((fl-a[i]/2)%a[i]!=0){
            cout<<0<<endl;
            return 0;
        }
    }
    int ans=1;
    m-=fl;
    ans+=m/l;
    cout<<ans<<endl;
}
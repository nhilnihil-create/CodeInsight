#include<bits/stdc++.h>
using namespace std;
#define ll   long long int
#define T int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define PI 3.141592653589793238462643383

long double dist(long double x, long double y){
    long double sx = (x*x);
    long double sy = (y*y);
    return sqrt(sx+sy);
}

int main (){
    fast;
    long double x,y;
    ll ans = 0;
    long double n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(dist(x,y) <= d) ans++;
    }
    cout<<ans<<endl;
}










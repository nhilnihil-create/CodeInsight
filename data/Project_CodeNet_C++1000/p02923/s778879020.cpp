#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<int,int>;

int main(){
    ll n;
    cin>>n;
    ll ans=0;
    ll sum=0;
    ll a;
    ll now=0;
    rep(i,n){
       cin>>a;
       if(now<a){
           now=a;
           sum=0;
        }else{
           now=a;
           sum++;
        }
       ans=max(ans,sum);
    }
    cout<<ans<<endl;
}

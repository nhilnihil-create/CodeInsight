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
    ll a,b;
    ll ans;
    cin>>a>>b;
    b=min(b,a+2019);
    ans=2018;
    for(ll i=a;i<b;i++){
        for(ll k=i+1;k<=b;k++){
            ans=min(ans,i*k%2019);
        }
    }
   cout<<ans<<endl;
}

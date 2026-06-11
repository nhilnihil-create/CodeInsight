#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<math.h>

#define forn(x,n,s) for(int i = x; i < n; i += s )
#define forr(x,n,s) for(int i = x; i>=n; i -= s)
#define PI 3.14159265358979323846264338327950L

using namespace std;

void go(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
  #endif
} 
long long int mod = 1e9+7;

int main(){
    go(); 

    // code here
    int a,b,h,m;cin>>a>>b>>h>>m;
    long double angle = 2 * PI * ((long double)h/12.0 + ((long double)m/60.0)/12.0 - (long double)m/60.0);
    long double ans = (long double)(a*a + b*b) - (long double)( 2 * a * b * cosl(angle));
    cout << std::fixed;
    cout << std::setprecision(20);
    cout<<sqrtl(ans);
}





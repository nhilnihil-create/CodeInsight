#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,b)  for(int i=0;i<(int)(b);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(int i=a;i<=(int)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
    cs
    ll a,b,c;
    cin>>a>>b>>c;
    (4*a*b<(c-a-b)*(c-a-b))&&c>(a+b) ? cout<<"Yes" : cout<<"No"; 
}
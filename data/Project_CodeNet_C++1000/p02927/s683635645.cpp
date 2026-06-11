#include <stdlib.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

int main() {
  int a,b;
  cin>>a>>b;
  int count=0;
  for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
      int c=j/10;
      int d=j%10;
      if(c>=2&&d>=2&&i==c*d){
        count++;
      }
    }
  }
  cout<<count<<endl;

}

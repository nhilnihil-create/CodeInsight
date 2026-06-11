#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include<set> 
#include<math.h>
#define pai arccos(-1);
#define keta(n) cout << fixed << setprecision((n));
#define ll long long;

int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  int count = 0;
  while(a>=b){
    b*=2;
    count++;
  }
  while(b>=c){
    c*=2;
    count++;
  }
  if(count<=k)cout<<"Yes";
  else cout<<"No";

}

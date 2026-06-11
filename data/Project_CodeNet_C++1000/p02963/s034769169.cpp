#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int m=1000000000;

int main(){
  ll s;
  cin >> s;
  int a=(s-1)/m+1;
  int b=m-(s-1)%m-1;
  
  if(s==1e18) cout << 0 << ' ' << 0 << ' ' << m <<  ' ' << 0 << ' ' << 0 << ' ' << m;
  else cout << 0 << ' ' << 0 << ' ' << m <<  ' ' << 1 << ' ' << b << ' ' << a;
  return 0;
}
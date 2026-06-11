#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,a,b;	cin >> n >> a >> b;
  long long ans=0;
  ans+=n/(a+b)*a;
  n-=n/(a+b)*(a+b);
  ans+=min(a,n);
  cout << ans;
}
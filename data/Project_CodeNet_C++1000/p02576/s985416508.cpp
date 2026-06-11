#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

typedef long long int ll;

int main(){
  double n,x,t;
  cin >> n >> x >> t;

  int ans=ceil(n/x)*t;
  cout << ans << endl;
}

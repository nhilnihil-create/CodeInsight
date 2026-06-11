#include<bits/stdc++.h>
using namespace std;

int eu(int a, int b){ // a > b
  int r=a%b;
  if(r==0) return b;
  return eu(b,r);
}

int main(){
  int n,m;
  cin>> n >> m;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin>> a[i];
  
  for(int i=0; i<n; i++) a[i]/=2;
  sort(a.begin(),a.end()); reverse(a.begin(),a.end());
  int64_t lcm=a[0];
  for(int i=1; i<n; i++){
    int64_t new_lcm=lcm*a[i]/eu(lcm,a[i]);
    if(new_lcm/lcm%2==0 || new_lcm/a[i]%2==0 || new_lcm>m){
      cout<< 0 << endl;
      return 0;
    }
    lcm=new_lcm;
  }
  
  int ans=0;
  for(int i=lcm; i<=m; i+=2*lcm) ans++;
  cout<< ans <<endl;
  return 0;
}
//a/2の奇数倍が最小公倍数(b)ならbの奇数倍が半公倍数
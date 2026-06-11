#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n;
  double m;
  cin>>n>>m;
  vector<double> a(n);
  double sum=0;
  rep(i,n){
    cin>>a[i];
    sum+=a[i];
  }
  double x=1/(4*m);
  double ans=0;
  rep(i,n){
    if(a[i]>=sum*x){
      ans++;
    }
  }
  if(ans>=m) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

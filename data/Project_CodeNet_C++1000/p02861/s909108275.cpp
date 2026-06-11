#include<bits/stdc++.h>
using namespace std;
int n;
int x[10],y[10];
double dis(int i,int j){
    double xx=x[i]-x[j];
    double yy=y[i]-y[j];
  return sqrt(xx*xx+yy*yy);
}
void solve(){
  int n1=1;
  cin >> n;
  for(int i=1;i<=n;i++)cin >> x[i] >> y[i];
  long double sum=0.0;
  vector<int> v(n);
  for(int i=0;i<n;i++)v[i]=i+1;
  for(int i=1;i<=n;i++)n1*=i;
  do{
    for(int i=0;i<n-1;i++)sum+=dis(v[i],v[i+1]);
  }while(next_permutation(v.begin(),v.end()));
  cout << fixed << setprecision(10) << (double)sum/n1 << endl;
  return;
}
int main(){
  solve();
}
  
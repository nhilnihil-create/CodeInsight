#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod=1e9+7;

signed main(){
  int n;
  cin>>n;
  double ans1=0;
  double ans2=0;
  double ans3=0;
  double ans4=0;
  vector<double> a(n);
  vector<double> b(n);

  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
  }
  for(int i=0;i<n;i++){
    ans1+=abs(a[i]-b[i]);
    ans2+=(a[i]-b[i])*(a[i]-b[i]);
    ans3=max(ans3,abs(a[i]-b[i]));
    ans4+=abs(a[i]-b[i])*abs(a[i]-b[i])*abs(a[i]-b[i]);
  }
  cout<<fixed<<setprecision(20)<<ans1<<endl;
  cout<<sqrt(ans2)<<endl;
  cout<<pow(ans4,1.0/3.0)<<endl;
  cout<<ans3<<endl;
}


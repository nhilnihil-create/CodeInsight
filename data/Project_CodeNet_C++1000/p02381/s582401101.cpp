#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod=1e9+7;

signed main(){
  while(true){
    int n;
    cin>>n;
    if(!n)break;
    vector<int> a(n);
    double ave=0;
    for(int i=0;i<n;i++){
      cin>>a[i];
      ave+=a[i];
    }
    ave/=n;
    double ve=0;
    for(int i=0;i<n;i++)ve+=(a[i]-ave)*(a[i]-ave);
    ve/=n;
    ve=sqrt(ve);
    cout<<fixed<<setprecision(20)<<ve<<endl;
  }
}


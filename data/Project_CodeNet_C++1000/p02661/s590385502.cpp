#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<int> a(n),b(n);
  rep(i,n) cin>>a[i]>>b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());	
  double x=(a[n/2]+a[(n-1)/2])/2.0;
  double y=(b[n/2]+b[(n-1)/2])/2.0;
  if(n%2==0){
    x*=2;
    y*=2;
  }
  int ans=y-x+1;
  cout<<ans<<endl;
}
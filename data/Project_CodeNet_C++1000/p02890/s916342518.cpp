#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

int main(){

  int n;
  cin >> n;
  int a[n];
  int c[n];
  rep(i,n) c[i]=0;
  rep(i,n){
    cin >> a[i];
    c[--a[i]]++;
  }
  int pa[n+1];
  rep(i,n+1) pa[i]=0;
  rep(i,n){
    //    cout << c[i] << endl;
    pa[c[i]]++;
  }
  ll s[n+1];
  ll pn[n+1];
  pn[0]=0;
  s[0]=0;
  rep1(i,n){
    s[i]=s[i-1];
    s[i]+=pa[i]*i;
    pn[i]=pn[i-1];
    pn[i]+=pa[i];
  }
  ll ss[n+1];
  rep(i,n+1){
    ss[i]=s[i];
    ss[i]+=(pn[n]-pn[i])*i;
    //    cout << s[i] << " " << ss[i] << endl;
  }
  rep1(i,n){
    ll lb=0;
    ll ub=n+1;
    while(ub-lb>1){
      ll mid=(lb+ub)/2;
      if(i*1LL*mid<=ss[mid]){
	lb=mid;
      }
      else{
	ub=mid;
      }
    }
    cout << lb << endl;
  }
  
  return 0;

}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  if(n==2){
      cout << a[1]-a[0] << endl;
      cout << a[1] << " " << a[0] << endl;
      return 0;
  }
  ll m=0;
  ll t=0;
  if(a[0]>0){
    t=a[0]-a[1];
  }
  else if (a[n-1]<0){
    t=a[n-1]-a[n-2];
  }
    
  if(a[0]>0){    
    rep1(i,n-1) m+=a[i];
    m-=a[0];
    cout << m << endl;
    cout << a[0] << " " << a[1] << endl;
    t=a[0]-a[1];
    rep1(i,n-3){
      cout << t << " " << a[i+1] << endl;
      t=t-a[i+1];
    }
    cout << a[n-1]  <<" " << t << endl;
  }
  else if (a[n-1]<0){
    rep(i,n) m+=abs(a[i]);
    m-=abs(a[n-1])*2;
    cout << m << endl;
    cout << a[n-1] << " " << a[n-2] << endl;
    t=a[n-1]-a[n-2];
    rep(i,n-2){
      cout << t << " " <<  a[i] << endl;
      t=t-a[i];
    }
  }
  else{
    rep(i,n) m+=abs(a[i]);
    cout << m << endl;
    t=a[0];
    for(int i=n-2; i>=0; i--){
      if(a[i]>0){
	cout << t << " " << a[i] << endl;
	t= t-a[i];
      }
      else if(t<=0){
	cout << a[n-1] << " " << t << endl;
	t = a[n-1] -t;
	if(i==0) break;
      }
      if(a[i]<=0){
	if(i==0)break;
	cout << t << " " << a[i] << endl;
	t= t-a[i];
      }      
    }
  }
  return 0;
    

}

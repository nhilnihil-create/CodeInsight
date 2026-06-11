#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main() {
  ll t1,t2,a1,a2,b1,b2;
  cin>>t1>>t2>>a1>>a2>>b1>>b2;
  if (a1*t1+a2*t2==b1*t1+b2*t2) {
    cout<<"infinity"<<endl;
    return 0;
  }
  if (a1*t1+a2*t2>b1*t1+b2*t2) {
    swap(a1,b1);
    swap(a2,b2);
  }
  if (a1*t1<b1*t1) {
    cout<<0<<endl;
    return 0;
  }
  if (((a1-b1)*t1)%((b1*t1+b2*t2)-(a1*t1+a2*t2))==0) {
    cout<<(((a1-b1)*t1)/((b1*t1+b2*t2)-(a1*t1+a2*t2))+1)*2-2<<endl;
    return 0;
  }
  cout<<(((a1-b1)*t1)/((b1*t1+b2*t2)-(a1*t1+a2*t2))+1)*2-1<<endl;
  return 0;
}
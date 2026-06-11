#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll t1,t2,a1,a2,b1,b2;cin>>t1>>t2>>a1>>a2>>b1>>b2;

  if(t1*a1+t2*a2==t1*b1+t2*b2) { cout<<"infinity"<<endl; return 0; }

  // A always runs long
  if(t1*a1+t2*a2<t1*b1+t2*b2) {
    swap(a1,b1);
    swap(a2, b2);
  }

  if(a1>b1) { cout<<0<<endl; return 0; }

  ll diff = (t1*a1+t2*a2) - (t1*b1+t2*b2);

  ll t1_diff = b1*t1-a1*t1;

  ll result=(t1_diff/diff)*2+1;
  if(t1_diff%diff==0)result--;
  cout<<result<<endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ll N,A,B;
  cin>>N>>A>>B;
  ll x=A,y=B;
  A=min(x,y);
  B=max(x,y);
  if((B-A)%2==0){cout<<(B-A)/2<<endl;}
  else{
    ll wayto1=(A-1+B-1+1)/2;
    ll waytoN=(N-A+N-B+1)/2;
    cout<<min(wayto1,waytoN)<<endl;
  }
}
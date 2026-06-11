#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ll N,A,B;
  cin>>N>>A>>B;
  ll x=A,y=B;
  if(x>y){
    if((x-y)%2==0){cout<<(x-y)/2<<endl;return 0;}
  }
  else if(x<y){
    if((y-x)%2==0){cout<<(y-x)/2<<endl;return 0;}
  }
  A=min(x,y);
  B=max(x,y);
  ll wayto1=(A-1+B-1+1)/2;
  ll waytoN=(N-A+N-B+1)/2;
  cout<<min(wayto1,waytoN)<<endl;
}
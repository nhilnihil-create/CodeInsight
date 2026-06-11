 #include <bits/stdc++.h>
using namespace std;
long long n,i,j,c,x,a,b;
bool res=true;
int main(){
  cin>>n>>a>>b;
  if(a&1&&b&1||!(a&1)&&!(b&1))cout<<b-(a+b)/2;
  else cout<<min(n-b,a-1)+(b-a-1)/2+1;
}
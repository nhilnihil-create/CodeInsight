#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
int main(){
  long long a;
  cin>>a;
  long double x=a;
  a*=100;
  a/=108;
  if(a*1.08==x && a*1.08<x+1){cout<<a<<endl;return 0;}
  if((a+1)*1.08>=x && (a+1)*1.08<x+1){cout<<a+1<<endl;return 0;}
  if((a-1)*1.08<=x && (a-1)*1.08>x+1){cout<<a-1<<endl;return 0;}
  cout<<":("<<endl;
} 
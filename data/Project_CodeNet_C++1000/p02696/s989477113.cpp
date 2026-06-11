#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll a,b,n; cin>>a>>b>>n;
  cout<<(a*min(n,b-1))/b<<endl;
}

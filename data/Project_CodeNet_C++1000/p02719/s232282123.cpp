#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
  ll n,k;cin>>n>>k;
  cout<<min(n%k,k-n%k)<<endl;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long int n,k;
  cin>>n>>k;
  long long int sum=0;
  for(long long int i=k;i<=n+1;i++){
    sum +=i*(n-i+1)+1;
  }
  cout<<sum%(1000000007);

}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;

int main() {
  ll N;
  cin>>N;
  vector<ll> a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  if(N%3==0&&a[0]==a[N/3-1]&&a[N/3]==a[N*2/3-1]&&a[N*2/3]==a[N-1]&&(a[0]|a[N/3])-(a[0]&a[N/3])==a[N*2/3]){
    cout<<"Yes";
  }
  else if(a[0]==a[N-1]&&a[0]==0){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }
  
}
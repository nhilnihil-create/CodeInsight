#include<iostream>
#include<vector>
using namespace std;
using ll=long long;

int main(){
  int n;
  cin>>n;
  ll now=1;
  ll MAX=1e18;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]==0){
      cout<<0<<endl;
      return 0;
    }
  }
  for(int i=0;i<n;i++){
    if(MAX/now<a[i]){
      cout<<-1<<endl;
      return 0;
    }
    else if(MAX<now*a[i]){
      cout<<-1<<endl;
      return 0;
    }
    now*=a[i];
  }
  cout<<now<<endl;
}
    
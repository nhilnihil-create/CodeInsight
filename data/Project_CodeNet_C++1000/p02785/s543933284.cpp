#include <bits/stdc++.h>
#include <vector>
#include <string.h>

typedef long long ll;
typedef long double lg;
using namespace std;

int main(){

  ll n,k,x;
  cin>>n>>k;

  vector<ll>a;

  for(int i=0;i<n;i++){
     cin>>x;
     a.push_back(x);
  }

  sort(a.begin(),a.end());

  if(k>= n){
    cout<<"0"<<endl;
    return 0;
  }


 ll sum=0;
  for(int i=0;i<n-k;i++)
 {
    sum += a[i];
  }

  cout<<sum<<endl;

return 0;
}
#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;
typedef pair<int,int> P;

const ll mod=1000000007;

int main() {
  ll a,b,k;
  cin >> a >> b >> k;
  if(k<=a)cout<<a-k<<" "<<b<<endl;
  else{
    k-=a;
    if(k<=b){
      cout<<0<<" "<<b-k<<endl;
    }
    else cout<<0<<" "<<0<<endl;
  }
}
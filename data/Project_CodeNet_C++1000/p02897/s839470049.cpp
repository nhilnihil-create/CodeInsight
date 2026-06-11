#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  double n;
  cin >> n;
  if((ll)(n/1)%2==0)cout << 0.5 << endl;
  else if(n==1) cout << 1 << endl;
  else{
    printf("%.12f",(n+1)/(2*n));
  }

}
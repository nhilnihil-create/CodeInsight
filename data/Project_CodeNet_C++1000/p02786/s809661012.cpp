#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll rec(ll a){
  if(a==1)return 1;
  else return 2*rec(a/2)+1;
}

int main(){

  ll h;
  cin >> h;
  cout << rec(h) << endl;

}
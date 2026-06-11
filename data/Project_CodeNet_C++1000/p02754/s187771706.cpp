#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  cout << n/(a+b)*a+min(n%(a+b),a);
  
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<VI> VVI;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;

bool is_prime(int n){
  bool res=true;
  if(n==1) return false;
  for(int i=2;i*i<=n;i++){
    if(n%i==0) res=false;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  bool prime[250001];
  for(int i=1;i<250000;i++){
    prime[i]=is_prime(i);
  }
    
  int n;
    
  while(cin>>n,n){
    int ans=0;
    for(int i=n+1;i<=2*n;i++){
      if(prime[i]) ans++;
    }
    cout << ans << endl;
  }
}
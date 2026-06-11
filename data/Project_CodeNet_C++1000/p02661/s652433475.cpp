#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
//#define INF 1e18
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n;
vector<ll> a,b;

int main(){
  cin >> n;
  rep(i,0,n){
    ll A,B;
    cin >> A >> B;
    a.push_back(A);
    b.push_back(B);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ll ans;
  if(n%2==1){
    ans = b[(n+1)/2-1] - a[(n+1)/2-1] + 1;
  }else{
    ans = (b[n/2-1]+b[n/2]) - (a[n/2-1]+a[n/2])+1;
  }

  cout << ans << endl;

  return 0;
}

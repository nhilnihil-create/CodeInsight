#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


// i * j = n
// i + j -> min?
int main(){
  ll n;
  cin >> n;

  ll mn = (n-1) + (1-1);

  for(int i = 2; i <= sqrt(n); i++){
    if(n%i == 0){
      mn = min(mn, i-1 + n/i-1);
    }
  }
  cout << mn << endl;
}

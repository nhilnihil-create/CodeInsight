#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int a,b; cin >> a >> b;

  if(a > b) swap(a,b);

  int ans;
  if(a == 1 && b == 2) { 
    ans = 3;
  }
  if(a == 2 && b == 3) { 
    ans = 1;
  }
  if(a == 1 && b == 3) { 
    ans = 2;
  }
  cout << ans << endl;

}

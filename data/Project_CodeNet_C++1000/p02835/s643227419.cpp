#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);

  int a,b,c; cin >> a >> b >> c;
  string ans;
  if(a+b+c>=22){
    ans = "bust";
  } else {
    ans = "win";
  }
  cout << ans << endl;
}

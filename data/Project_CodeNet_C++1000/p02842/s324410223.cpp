#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int n;
cin >> n;
string ans = ":(";
for(int i = 1; i <= 50000; i++){
  if((int)(i*1.08) == n){
    ans = to_string(i);
    break;
    
  }
}

cout << ans << endl;

}

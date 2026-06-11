#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD=1000000007;
#define PI acos(-1)
using namespace std;
int main(){
      int x,y; cin >> x >> y;
      if(x>=0 && x <= 9 && y >=0 && y <= 9 )
      cout << x*y << endl;
      else cout << -1 << endl;
}
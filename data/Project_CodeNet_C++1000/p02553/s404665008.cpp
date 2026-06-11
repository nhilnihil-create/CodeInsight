#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
 
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main(void){
  ll  a,b,c,d;
  cin >> a >> b >> c >> d;
  ll ma = max(a*c,b*d);
  ma = max(ma,a*d);
  ma = max(ma,b*c);
  cout << ma;
}
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
 
   
int main(){
  ll a,v,b,w,t;
  cin >> a >> v >> b >> w >> t;
  ll dif=abs(b-a);
  ll mv=(v-w)*t;
  if(mv>=dif)cout << "YES" << endl;
  else cout << "NO" << endl;
} 
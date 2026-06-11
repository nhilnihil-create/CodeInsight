#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;

int main() {
  
  int n,a,b,c,d,x;
  long long la,lb,lc,lx;
  double da,db,dc;
  string s,ss,sss;
  
  int ans = 0;
  string anss = "";
  
  cin >> n >> a;
  vector<int> va(n);
  //vector<int> vb(n);
  //vector<int> vc(n-1);
  rep(i,0,n) cin >> va.at(i);
  //rep(i,0,n) cin >> vb.at(i);
  //rep(i,0,n-1) cin >> vc.at(i);
  //int ab [] = {0 , 1 , 3 , 1 , 2 , 1 , 2 , 1 , 1 , 2 , 1 , 2 , 1};
  //int result3 = std::max({a, b, c});
//--------------------------------------------------------------------------------
int count = 0;
  while(ans<n){
  	ans += (a*2+1);
    count++;
  }

  cout << count << endl;
 // cout << fixed << setprecision(5) << ans << endl;

}
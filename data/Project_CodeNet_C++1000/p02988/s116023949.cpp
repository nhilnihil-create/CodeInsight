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
  
  double ans = 0;
  string anss = "";
  
  cin >> n;
  vector<int> va(n);
  //vector<int> vb(n);
  //vector<int> vc(n-1);
 // vector<vector<int>> data(n, vector<int>(a));
 /* for (int i = 0; i < n; i++) {
    for (int j = 0; j < a; j++) {
      cin >> data.at(i).at(j);
    }
  }*/
  rep(i,0,n) cin >> va.at(i);
  //rep(i,0,n-1) cin >> vc.at(i);
  //int ab [] = {0 , 1 , 3 , 1 , 2 , 1 , 2 , 1 , 1 , 2 , 1 , 2 , 1};
  //int result3 = std::max({a, b, c});
//--------------------------------------------------------------------------------
int count = 0;
  rep(i,1,n-1){
    if(va.at(i) > va.at(i-1) && va.at(i+1) > va.at(i) || va.at(i) < va.at(i-1) && va.at(i+1) < va.at(i))count++;
  }
  cout << count << endl;
 // cout << fixed << setprecision(5) << ans << endl;

}
#include <bits/stdc++.h> //AtCoder
#include <atcoder/all> //AtCoder
#include <iostream> //Codeforces
#include <vector> //Codeforces

#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define Vi vector<int>
#define VVi vector<Vi>
#define Vs vector<string>
#define Vc vector<char>
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl

using namespace std;
using namespace atcoder;

/*int gcd(int a,int b){return b?gcd(b,a%b):a;}//最大公約数
int lcm(int a,int b){return a/gcd(a,b)*b;}//最小公倍数*/

/****************************** START ******************************/

signed main(){
  int N,Q;
  cin >> N >> Q;
  dsu d(N);
  int t,u,v;
  rep(i,0,Q){
    cin >> t >> u >> v;
    if (t){
      if (d.same(u,v)){
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else {
      d.merge(u,v);
    }
  }
}      
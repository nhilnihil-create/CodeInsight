#include <bits/stdc++.h>
using namespace std;
typedef bool boool;
typedef long long ll;
#define vl vector<ll>
#define vb vector<boool>
#define vs vector<string>
#define vp vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll, ll>>>
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define rep1(i, n) for (long long i=0; i<(long long)(n); i++)
#define rep2(i, s, e) for (long long i=(s); i<(long long)(e); i++)
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

int main(){
  double a, b, x;
  cin >> a >> b >> x;
  double s = x/a;
  double theta;
  if(s > a*b/2){
    theta = atan(2*(a*b-s)/(a*a));
    theta = theta/M_PI*180;
  }else{
    theta = atan(b*b/(2*s));
    theta = theta/M_PI*180;
  }
  cout << std::setprecision(10) << theta << endl;
  return 0;
}
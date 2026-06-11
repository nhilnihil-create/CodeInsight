#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
ll MOD = (1e9)+7;
const int dr[] = {+1, -1, +0, +0, +1, -1, +1, -1};
const int dc[] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int kx[] = {+1, +2, -1, -2, +1, +2, -1, -2};
const int ky[] = {+2, +1, +2, +1, -2, -1, -2, -1};
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
inline void fastIO(){
  ios_base::sync_with_stdio(0);cin.tie(0);
}
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }

#ifdef LOCAL
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", debug_out(__VA_ARGS__)
#else
#define debug(...) 47
#endif
#define pi 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482
double mind(double a,double b){
  if(a<b){
    return a;
  }
  return b;
}
int main(){
  fastIO();
  cout<<fixed;
  cout<<setprecision(32);
  double a,b,h,m;
  cin>>a>>b>>h>>m;
  double xA=a*cos(pi/2 - ((pi*(h*60+m))/360));
  double yA=a*sin(pi/2 - ((pi*(h*60+m))/360));
  double xB=b*cos(pi/2 - (pi*m)/30);
  double yB=b*sin(pi/2 - (pi*m)/30);
  cout<<sqrt(pow(xA-xB,2)+pow(yA-yB,2))<<endl;
  return 0;
}

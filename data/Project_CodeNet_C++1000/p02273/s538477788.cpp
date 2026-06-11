#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//#define ll long long
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;
ll n;
class Point{
public:
    double x;
    double y;
    Point(){

    }
    Point(double x,double y):x(x),y(y){

    }
};
void print(Point p){
  printf("%.10f %.10f\n",p.x,p.y);
}
void dfs(ll depth,Point p1,Point p2){
  if(depth == n){
    return;
  }else{
    vector<Point> vec(3);
    double tm1,tm2;
    vec[0].x = (2 * p1.x + p2.x) / 3;
    vec[0].y = (2 * p1.y + p2.y) / 3;
    tm1 = (p1.x + p2.x) / 2;
    tm2 = (p1.y + p2.y) / 2;
    vec[2].x = (p1.x + 2 * p2.x) / 3;
    vec[2].y = (p1.y + 2 * p2.y) / 3;
    vec[1].x = tm1 - (tm2 - vec[0].y) * sqrt(3);
    vec[1].y = tm2 + (tm1 - vec[0].x) * sqrt(3);
    dfs(depth+1,p1,vec[0]);
    print(vec[0]);
    dfs(depth+1,vec[0],vec[1]);
    print(vec[1]);
    dfs(depth+1,vec[1],vec[2]);
    print(vec[2]);
    dfs(depth+1,vec[2],p2);
  }
}
int main(){
  cin >> n;
  Point p1(0.0,0.0),p2(100.0,0.0);
  print(p1);
  dfs(0,p1,p2);
  print(p2);
}

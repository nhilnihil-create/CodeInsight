#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
//function area
void dist(long double x1, long double y1, long double x2, long double y2){
    long double dx = x1 - x2, dy = y1 - y2;
    cout << fixed << setprecision(5) << sqrtl(dx*dx + dy*dy) << endl;
}
//main area
int main(){
    long double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    dist(x1, y1, x2, y2);
}

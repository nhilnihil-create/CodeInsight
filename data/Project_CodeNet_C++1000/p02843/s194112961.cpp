#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
//struct area

//function area

//main area
int main(){
    int x;
    cin >> x;
    int ax = x/100;
    int maru = x%100;
    cout << (ax*5 < maru ? 0 : 1) << endl;
}
/*

18027
ax = 180, maru = 27
180回で27を作れるか？
ax*5 <> maru

*/
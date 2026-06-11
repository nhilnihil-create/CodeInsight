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
const int INF = 1e6;
using namespace std;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
int main(){
    char c[4];
    cin >> c[0] >> c[1] >> c[2] >> c[3];
    sort(c,c+4);
    if(c[0]==c[1] && c[2]==c[3] && c[1]!=c[2]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
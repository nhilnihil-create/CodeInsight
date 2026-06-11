#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

const int max_n = 10;
int n;
struct point{
    int x, y;
};
point pts[max_n];
double ans=0, cnt=0;
vector<int> v;

int main(){
    cin >> n;
    rep(i, n) {
        cin >> pts[i].x >> pts[i].y;
        v.push_back(i);
    }

    do{
        int X = pts[v[0]].x, Y = pts[v[0]].y;
        for(int i=1; i<n; i++){
            int nx = pts[v[i]].x, ny = pts[v[i]].y;
            ans += sqrt((X-nx)*(X-nx) + (Y-ny)*(Y-ny));
            X = nx, Y = ny;
        }
        cnt++;
    }while(next_permutation(v.begin(), v.end())); 
    ans /= cnt;
    printf("%.7f\n", ans);
    return 0;
}
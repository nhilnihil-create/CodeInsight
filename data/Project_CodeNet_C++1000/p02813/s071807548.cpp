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

const int max_n = 8;
int n, a, b, cnt=1;
int p[max_n], q[max_n];
vector<int> v;

int main(){
    cin >> n;
    rep(i, n) cin >> p[i], v.push_back(i+1);
    rep(i, n) cin >> q[i];

    do{
        bool isp = true, isq = true;
        for(int i=0; i<n; i++){
            if(v[i] != p[i]) {
                isp = false;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(v[i] != q[i]) {
                isq = false;
                break;
            }
        }
        if(isp) a = cnt;
        if(isq) b = cnt;
        cnt++;
    }while(next_permutation(v.begin(), v.end()));
    cout << abs(a-b) << endl;
    return 0;
}
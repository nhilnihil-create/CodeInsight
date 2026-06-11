#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int digit_sum(int n){
   if(n < 10)  return 1;
   return digit_sum(n/10) + 1;
}
int main()
{
    int N;
    cin >> N;
    int cnt = 0;
    rep2(i, 1, N+1)
    {
        if(digit_sum(i)%2 != 0) ++cnt;
    }

    cout << cnt << endl;
    return 0;
}
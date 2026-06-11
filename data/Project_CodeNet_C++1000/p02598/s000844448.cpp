#include<bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)
const long long INF = 1LL << 60;

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    int left=0;
    int right=1e9;
    while(right-left > 1){
      int c = (left+right)/2;
      ll sum=0;
      rep(i,N){
        sum+=((A[i]-1)/c);
      }
      if(sum<=K) right=c;
      else left=c;
    }
    cout << right << endl;

    return 0;
}

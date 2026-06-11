
#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
#define PI 3.14159265359
#define MOD (ll)1000000007
using namespace std;
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}


typedef long long ll;
ll INF = 1e+18;

int
main()
{
  int N, K; cin >> N >> K;
  vector<int> arr(N);
  rep(i, 0, N) cin >> arr[i];
  sort(arr.begin(), arr.end());
  int sum = 0;
  rep(i, 0, K){
    sum += arr[i];
  }
  cout << sum << endl;
}
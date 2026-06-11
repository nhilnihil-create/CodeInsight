#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()

ll N;
 
int main(){
  int n, l;
  cin >> n >> l;
  int sum = (l + l + n - 1) * n / 2;
  if(l>=0) cout << sum - l;
  else if(abs(l) < n) cout << sum;
  else cout << sum - (l + n - 1);
}
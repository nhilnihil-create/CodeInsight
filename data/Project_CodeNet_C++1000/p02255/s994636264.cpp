#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
#define pb push_back
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vii;

template <class X> void print(X Target){ cout << Target << '\n'; }

void solve(vi a)
{
  for (int i = 0; i < a.size() - 1; i++){
    cout << a[i] << " ";
  }
  print(a[a.size() - 1]);
}

signed main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vi array(n);

  for (int i = 0; i < n; i++) cin >> array[i];

  for (int i = 1; i < n; i++){
    solve(array);
    for (int j = i; j >= 0 && array[j - 1] > array[j]; j--){
      swap(array[j - 1], array[j]);
    }
  }
  solve(array);

  return (0);
}
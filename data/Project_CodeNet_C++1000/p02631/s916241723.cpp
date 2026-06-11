#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  ll b = 0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    b ^= a[i];
  }

  for(int i=0;i<n;i++){
    cout << (b^a[i]);
    if(i != n-1) cout << " ";
    else cout << "\n";
  }
}

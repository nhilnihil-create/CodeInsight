#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)

int main()
{
  int n;
  cin >> n;
  ll sum = 0;
  for (int i = 1; i <= n; i++)
  {
    int a = n / i;
    sum += (ll)i * a * (a + 1) / 2;
  }
  cout << sum;
  return 0;
}
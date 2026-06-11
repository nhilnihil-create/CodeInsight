#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define ull unsigned long long
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
int INF = 1001001001;
const int MOD=1e9+7;

int main() {
  string t;
  in t;
  rep(i,t.size())if(t[i] == '?') t[i] = 'D';
  cout<<t<<endl;
  return 0;
}

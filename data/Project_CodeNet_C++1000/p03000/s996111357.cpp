#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int bounce[100000] = {};
int n;
vector<int> l;
int x;

int main(){
  cin >> n >> x;
  l.resize(n);
  for (auto &&i : l)
  {
    cin >> i;
  }
  long long sum = 0;
  for (auto &&i : l)
  {
    bounce[sum + i]++;
    sum += i;
  }
  int ans = 0;
  for (size_t i = 0; i <= x; i++)
  {
    if (bounce[i] == 1)
    {
      ans++;
    }
    
  }
  
  
  cout << ++ans << endl;

}
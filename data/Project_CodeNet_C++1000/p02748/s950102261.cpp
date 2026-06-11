#include <bits/stdc++.h>
using namespace std;

int main() {
int A, B,M;
cin >>A>>B>>M;
vector<int>a(A);
vector<int>b(B);
for(int &x : a) cin >> x;
for(int &x : b) cin >> x;
vector<vector<int>>m;
for (int i = 0; i < M; i++)
{
  int x,y,z;
  cin >> x>>y>>z;
  m.push_back({x,y,z});
}
int mina = *min_element(a.begin(), a.end());
int minb = *min_element(b.begin(), b.end());
int min = mina+minb;
for (int i = 0; i < M; i++)
{
  int x=m[i][0], y=m[i][1], c=m[i][2];
  int val = a[x-1] + b[y-1] -c;
  if(min>val) min=val;
}
cout << min << endl;

  return 0;
}
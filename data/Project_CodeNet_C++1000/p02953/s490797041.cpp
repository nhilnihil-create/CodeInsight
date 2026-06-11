#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int n;
cin >> n;
vector<int> h(n);
rep(i,n) cin >> h.at(i);
bool ans = true;
for(int i = 1; i < n; i++){
  if(h.at(i)-h.at(i-1)>=1)h.at(i)--;
  else if(h.at(i)-h.at(i-1) < 0) ans = false;
}
cout <<(ans?"Yes":"No")<< endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n; 
  cin >> n;
  vi p(n), q(n);
  rep(i,n) cin >> p[i];
  rep(i,n) cin >> q[i];
  int a=0, b=0;
  do{
    a++;
  }while(next_permutation(p.begin(),p.end()));
  do{
    b++;
  }while(next_permutation(q.begin(),q.end()));
  cout << abs(a-b) << endl;
}

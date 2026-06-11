#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int> 

int main(){
  int N; cin >> N;
  vector<int> d(N);
  rep(i,N) cin >> d[i];
  sort(all(d));
  cout << d[N/2] - d[N/2-1] << endl;

  return 0;
}

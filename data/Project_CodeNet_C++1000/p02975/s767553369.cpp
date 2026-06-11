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
  map<int,int> d;
  int a;
  rep(i,N){
    cin >> a;
    d[a]++;
  }

  bool ok = false;
  if (d.size()==1 && d[0]==N) ok = true;
  else if (d.size()==2 && N%3==0 && d[0]==N/3) ok = true;
  else if (d.size()==3 && N%3==0){
    int tot_xor = 0, err = 0;
    vector<int> b;
    for (auto p:d){
      tot_xor ^= p.first;
      err += abs(p.second - N/3);
    }
    if (tot_xor==0 && err==0) ok = true;
  }
  cout << (ok? "Yes" : "No") << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}

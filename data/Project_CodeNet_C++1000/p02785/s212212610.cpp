#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  long long n,k;

  cin >> n >> k;

  long long sum =0;

  long long flag = 0;

  vector<int> h(n);

  rep(i,n){
    cin >> h.at(i);
  }

  sort(h.begin(),h.end(),greater());\

  if(k >= h.size()){
    cout << 0;
    return 0;
  }
  

  rep(i,k){
    h.erase(h.begin());
  }
  
  rep(i,h.size()){
    sum+=h.at(i);
  }

  cout << sum << endl;


}
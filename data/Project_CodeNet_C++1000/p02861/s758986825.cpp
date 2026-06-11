#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int kaizyou(int n){
  int a=1;
  for(int i=1;i<=n;i++){
    a *= i;
  }
  return a;
}
int main() {
  int n;
  cin >> n;
  vector<pii> p(n);
  for(int i=0;i<n;i++){
    cin >> p.at(i).first >> p.at(i).second;
  }
  double d = 0;
  sort(p.begin(),p.end());
  do{
    for(int i=0;i<n-1;i++){
      d += sqrt(pow(p.at(i+1).first-p.at(i).first,2.0) + pow(p.at(i+1).second-p.at(i).second,2.0));
    }
  }while(next_permutation(p.begin(),p.end()));
  cout << fixed << setprecision(10);
  cout << d/(double)kaizyou(n) << endl;
}
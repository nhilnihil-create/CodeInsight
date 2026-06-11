#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
int n;
  cin >> n;
  vector<int> w(n);
  int sum=0;
  for(int i=0;i<n;i++){
    cin >> w.at(i);
    sum+=w.at(i);
  }
  int suma=0;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    suma+=w.at(i);
    a.at(i)=abs(2*suma-sum);
  }
  sort(a.begin(),a.end());
  cout << a.at(0) << endl;
}


#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  int n;
  cin >> n;
  vector<int> b(n-1);
  for(int i=0;i<n-1;i++){
    cin >> b.at(i);
  }
  vector<int> a(n);
  a.at(0)=b.at(0);
  a.at(n-1)=b.at(n-2);
  for(int i=1;i<n-1;i++){
    a.at(i)=min(b.at(i),b.at(i-1));
  }
  ll sum=0;
  for(int i=0;i<n;i++){
    sum=sum+a.at(i);
  }
  cout << sum << endl;
}


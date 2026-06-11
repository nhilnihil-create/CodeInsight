#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a;
  string b;
  cin>>a>>b;
  cout<<a*stoi(b.erase(b.find('.'),1))/100<<endl;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll s;
  cin >> s;
  cout << "0 0 1000000000 1 " << 999999999-(s-1)%1000000000 << ' ' << (s-1)/1000000000+1 << endl;
}
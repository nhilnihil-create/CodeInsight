#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t n,d;
  cin >> n >> d;
  int count = 0;
  int64_t a,b;
  vector<pair<int,int>>  v;
  for(int i = 0; i<n; i++){
    cin >> a >> b;
    if(d*d >= a*a + b*b) count++;
  }
  cout << count << endl;
}
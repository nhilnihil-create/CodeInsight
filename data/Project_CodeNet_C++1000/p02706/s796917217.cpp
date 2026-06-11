#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  vector<int> a;
  cin >> n >> m;
  long long sum = 0;
  for(int i = 0; i < m; i++){
    int b;
    cin >> b;
    sum += b;
    if( sum > n ) break;
  }
  cout << ( sum > n ? -1 : n - sum ) << endl;
}

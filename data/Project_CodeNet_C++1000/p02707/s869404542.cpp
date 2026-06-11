#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<long long>syain(n,0ll);
  for(int i = 1; i < n ; i++){
    int a; cin >> a;
    syain.at(a-1)++;
  }
  for(int i = 0; i < n; i++){
    cout << syain.at(i) << endl;
  }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  int days = 0;
  for (int i = 0; i < m; i++){
    int a;
    cin >> a;
    days = days+a;
  }
  if (days <= n){
    cout << n - days << endl;
  }else{
    cout << -1 << endl;
  }
}
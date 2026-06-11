#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> a(n);
  int max_i;
  int max_num = 0,semi_max_num = 0;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(a > max_num){
      max_i = i;
      max_num = a;
    }
    else if(a > semi_max_num)
      semi_max_num = a;
  }
  for(int i = 0; i < n; i++){
    if(i == max_i)
      cout << semi_max_num << endl;
    else
      cout << max_num << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  vector<int> c(n);
  for(int i=0;i<n;i++){
    cin >> c.at(i);
  }
  int a =0;//初期値
  for ( int i = 0; i < n-1; i++){//i番目のおいしさ
    for(int j = i+1; j < n;j++){ //i+1番目以降のおいしさ
    a += c.at(i)*c.at(j);//ex)1番目＝2~4　2番目＝3・4 3*4　総当たり　
    }
  }
  cout << a << endl;
}
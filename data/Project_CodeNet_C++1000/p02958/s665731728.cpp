#include <bits/stdc++.h>
using namespace std;

int n;
int c = 0;
int p[50];

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> p[i];
  }
  for(int i = 1; i <= n; ++i){
    if(i != p[i-1]){
      c += 1;
    }
  }
  if(c == 0 || c == 2){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
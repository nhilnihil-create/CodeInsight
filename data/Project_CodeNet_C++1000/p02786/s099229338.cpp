#include<bits/stdc++.h>
using namespace std;

long long a(long long i){
  if(i == 1) return 1;
  else{
    return 2 * a(i / 2) + 1;
  }
}

int main(){
  long long h;
  cin >> h;
  cout << a(h) << endl;
}
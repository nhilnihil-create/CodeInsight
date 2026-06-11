#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >>n;
  int64_t a=0;
  int b=0;
  for(int i=0;i<n;i++){
     b++;
    if(b%3!=0&&b%5!=0){
      a+=b;
    }
  }
  cout<<a;
}

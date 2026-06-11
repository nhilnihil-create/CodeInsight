#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int a,b;
  cin >> a >> b;

  int count = 0;
  int tap=1;

  while(tap<b){
    tap--;
    tap+=a;
    count++;
  }

  cout << count;
}
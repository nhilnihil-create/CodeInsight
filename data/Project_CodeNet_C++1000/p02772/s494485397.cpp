#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i = (s);i<(int)(n);i++)

int main(){
  int n;
  cin >> n;
  int a = 0;
  int sum = 0;
  int k[n];
  rep(i , n){
    cin >> k[i];
    if(k[i]%2 == 0){
      sum++;
      if(k[i]%3 == 0 || k[i]%5 == 0)a++;
    }
  }
  if(a == sum)cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}

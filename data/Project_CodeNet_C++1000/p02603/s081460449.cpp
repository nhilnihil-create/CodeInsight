#include <iostream>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
  long long n,money=1000;
  cin >> n;
  int a[n+1];
  rep(i,n){
    cin >> a[i];
  }
  a[n] = 0;
  
  rep(i,n){
    long long count=0,kabu=0;
    while(a[i] < a[i+1]){
      i++;
      count++;
    }
    kabu = money / a[i-count];
    money += (a[i] - a[i-count]) * kabu;
  }
  
  cout << money << endl;
  
  return 0;
}

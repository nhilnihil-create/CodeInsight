#include<iostream>
#include<string>
using namespace std;
int main(){
  long long n, c, s = 0, k = 0, a = 0;
  cin >> n >> c;
  s = n % c;
  k = -1 * (s - c);
  if(s > k){
    cout << k << "\n";
    return 0;
  }
  cout << s << "\n";
}
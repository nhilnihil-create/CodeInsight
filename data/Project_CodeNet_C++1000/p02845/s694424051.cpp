#include <iostream>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long r=0, g=0, b=0;
  long long ans = 1;
  for(long long i=0; i<n; i++){
    long long num;
    cin >> num;
    long long tmp = 0;
    char which;
    if(b == num){
      tmp++;
      which = 'b';
    }
    if(g == num){
      tmp++;
      which = 'g';
    }
    if(r == num){
      tmp++;
      which = 'r';
    }
    ans *= tmp;
    ans %= 1000000007;
    if(which == 'r') r++;
    else if(which == 'g') g++;
    else b++;
  }
  cout << ans << endl;
  return 0;
}
    

#include<iostream>
#include<cmath>
using namespace std;
bool isprime(long x){
    if(x == 2) 
      return true;
    if(x % 2 == 0 || x < 2) 
      return false;
    long j = 3;
    while(j <= sqrt(x)){
      if(x % j == 0) 
        return false;
      j += 2;
    }
    return true;
    
}

int main(){
  long n, cnt;
  cin >> n;
  for(int i = 0; i < n; i++){
    long x;
    cin >> x;
    if(isprime(x)) cnt++;
  }
  cout << cnt << "\n";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
 long long N; cin >> N;
 long long ans = 1000000000000;
 for(int i = 1; i <= sqrt(N); i++){
   if(N % i == 0){
     long long a = i;
     long long b = N / i;
     if(ans > (a + b - 2)) ans = a + b - 2;
  }
 }
  cout << ans << endl;
}
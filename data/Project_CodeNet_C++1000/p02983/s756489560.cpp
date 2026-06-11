#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long L,N,min = 99999999999;
  cin >> L >> N;
  for(long long i = L;i <= N;i++){
    for(long long j = L;j <= N;j++){
      if((i * j) % 2019 < min && i != j){
		min = (i * j) % 2019;
      }
      if(min == 0){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  cout << min << endl;

return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(long long i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,sum = 0;
  cin >> N;
  froop1(1,N + 1){
    if(i % 3 != 0 && i % 5 != 0){
      sum += i;
    }
  }
  cout << sum << endl;

}
#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,K,border;
  cin >> N >> K >> border;
  vector<long long> b(N,0);
  froop1(0,K){
    b.at(i) = border;
  }
  froop1(0,N){
	if(b.at(i) == 0){
      if(border < 1000000000LL){
      b.at(i) = border + 1;
      }else{
		b.at(i) = 1;
    }
    }
  }
  froop1(0,N){
	cout << b.at(i);
    if(i != N - 1){
      cout << " ";
    }else{
      cout << endl;
    }
  }

return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,M;
  cin >> N >> M;
  long long ans = N % M;
  if(ans > abs(ans - M)){
    cout << abs(ans - M) <<endl;
  }else{
    cout << ans << endl;
  }
}
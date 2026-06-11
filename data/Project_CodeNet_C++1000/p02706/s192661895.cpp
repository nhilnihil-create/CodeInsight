#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N,limit;
  cin >> limit >> N;
  int sum = 0;
  froop1(0,N){
    int a;
    cin >> a;
    sum += a;
  }
  if(limit < sum){
	cout << -1 << endl;
  }else{
    cout << limit - sum << endl;
  }
return 0;
}
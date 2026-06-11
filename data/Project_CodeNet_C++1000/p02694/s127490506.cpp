#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N;
  cin >> N;
  long long mon = 100LL,count = 0;
  while(mon < N){
    mon += mon / 100LL;
    count++;
  }
  cout << count << endl;
}
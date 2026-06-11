#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
using ll = long long;
int main(){
	int n,sum=0;
  cin >> n;
  for(int i = 1;i<=n;i++){
  	if(1 <= i && i <= 9 || 100 <= i&& i <= 999 || 10000 <= i && i <= 99999)sum++;
  }
  cout << sum <<endl;
  return 0;
}

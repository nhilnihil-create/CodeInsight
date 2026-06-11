#include <bits/stdc++.h>
using namespace std;
long long int dis(long long int a,long long int b){
  if(a>=b){
    return a-b;
  }else{
	return b-a;
  }
}

int main() {
  long long int N,K,ans;
  cin >> N >> K;
  ans=N%K;
  if(ans>=dis(ans,K)){
    cout << dis(ans,K);
  }else{
    cout << ans;
  }
}

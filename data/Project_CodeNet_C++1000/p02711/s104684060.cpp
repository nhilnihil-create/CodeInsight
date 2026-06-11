#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,flag=0;
  cin >> N;
  for(int i=0;i<3;i++){
	if(N%10==7) flag++;
    N/=10;
  }
  if(flag){
    cout<<"Yes";
  }else{
    cout<<"No";
  }
}
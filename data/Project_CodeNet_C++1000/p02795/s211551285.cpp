#include<bits/stdc++.h>
using namespace std;

int main(){
  double H , W, N;
  cin >> H >> W >> N;
  int ans;
  
  if(H >= W){
	ans = ceil(N/H);
  }
  else{
    ans = ceil(N/W);
  }
  cout << ans << endl;
}
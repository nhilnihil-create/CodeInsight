#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N,sw = 1;
  cin >> N;
  vector<int> stairs(N);
  froop1(0,N){
cin >> stairs.at(i);
  }
  froop1(0,N - 1){
    if(stairs.at(i) <= stairs.at(i + 1) - 1){
      stairs.at(i + 1)--;
    }
    if(stairs.at(i) > stairs.at(i + 1)){
      sw = 0;
      break;
    }
  }
  if(sw == 0){
cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }

return 0;
}
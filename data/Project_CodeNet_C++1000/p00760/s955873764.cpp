#include <iostream>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < n ; i++)

int main()
{
  int n;
  cin >> n;
  while(n--){
    int y, m, d, ans = 0;
    cin >> y >> m >> d;
    
    for(int i = m ; i <= 10 ; i++){
      if(i == m){
	if(y%3 == 0 || i%2 == 1){
	  ans += 20 - d + 1;
	}else{
	  ans += 19 - d + 1;
	}
      }else{
	if(y%3 == 0 || i%2 == 1){
	  ans += 20;
	}else{
	  ans += 19;
	}
      }
    }
    
    for(int i = y+1 ; i < 1000 ; i++){
      if(i%3==0){
	ans += 20*10;
      }else{
	ans += 19*5 + 20*5;
      }
    }
    cout << ans << '\n';
  }
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;
typedef long long ll;

int main(){
  ll L,R;
  cin >> L >> R;
  int ans=2019;
  if(R-L>=2019){
    ans = 0;
  }else{
    for(ll i=L;i<R;i++){
      for(ll j=i+1;j<R+1;j++){
	int n = i%2019;
	int m = j%2019;
	ans=min(ans,(n*m)%2019);
      }
    }
  }
  cout << ans << endl;
}


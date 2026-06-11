#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

int main(){

  while(1){
    int N;
    cin >> N;
    if(N==0)break;
    int ans=0;
    rep(i,0,N){
      rep(j,i,N){
	int sum=0;
	for(int k =i+1;k<j+1;k++){
	  sum += k;
	}
	if(sum == N) ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
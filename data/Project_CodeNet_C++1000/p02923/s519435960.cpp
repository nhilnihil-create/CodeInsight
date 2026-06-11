#include <iostream>
using namespace std;

int main() {
    int N,ans=0,buf=0;
    cin >> N;
    int h[N];
    cin >> h[0];
  	for(int i=1;i<N;i++){
      cin >> h[i];
      if(h[i-1]>=h[i])buf++;
      else{
        if(ans<buf) ans = buf;
        buf=0;
      }
	}
    if(ans<buf) ans = buf;
	cout << ans << endl;
}
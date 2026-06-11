#include<iostream>
using namespace std;
int main(){
  int ans=0,i,m=0,n,h[100010];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> h[i];
  }
  for(i=1;i<n;i++){
  	if(h[i-1]>=h[i]){
  		m++;
  	}
  	else{
      ans=max(ans,m);
      m=0;
    }
  }
  ans=max(ans,m);
  cout << ans << endl;
  return 0;
}

    
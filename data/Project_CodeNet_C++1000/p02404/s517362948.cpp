#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,i,j;
  while(1){
    cin >> h >> w;
      if(h==0 && w==0) break;
    for(j=1;j<=h;j++){
      for(i=1;i<=w;i++){
	if(j==1 || j==h){
	  cout << '#';
	}else{
	  if(i==1 || i==w) cout << '#';
	  else  cout << '.';
	}
      }
      cout << endl;
    }
    cout <<endl;
  }
  return 0;
}




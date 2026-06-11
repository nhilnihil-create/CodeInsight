#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W;bool flag = false;
  while(1){
    cin >> H >> W;
    if(H==0&&W==0)break;
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
	if(j==0){
	  if(i%2 == 0){
	    cout << '#';
	    flag = true;
	  }
	  else{
	    cout << '.';
	    flag = false;
	  }
	}
	else{
	  if(flag == true){
	    cout << '.';
	    flag = false;
	  }
	  else{
	    cout << '#';
	    flag = true;
	  }
	}
      }
      cout << endl;
    }
    cout << endl;
  }
  
}
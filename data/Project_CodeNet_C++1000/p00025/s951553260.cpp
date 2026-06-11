#include<iostream>
using namespace std;
int main(){
  int a[4],b[4];
  while(cin >>a[0]>>a[1]>>a[2]>>a[3]>>b[0]>>b[1]>>b[2]>>b[3]){
    bool fa[4] = {false};
    bool fb[4] = {false};
    int ans[2] = {0};
    for(int i=0; i<4; i++){
      if(a[i] == b[i]){
	fa[i] = true;
	fb[i] = true;
	ans[0]++;
      }
    }
    for(int i=0; i<4; i++){
      if(!fb[i]){
	for(int j=0; j<4; j++){
	  if(!fa[j] && a[j] == b[i]){
	    fa[j] = true;
	    fb[i] = true;
	    ans[1]++;
	    break;
	  }
	}
      }
    }
    cout <<ans[0]<<" "<<ans[1]<<endl;
  }
  return 0;
}
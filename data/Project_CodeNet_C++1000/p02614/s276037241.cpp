#include <iostream>
using namespace std;
int main(void){
  int h,w,k;
  cin>>h>>w>>k;
  string a[h];
  int re=0;
  for(int i=0;i<h;i++){
    cin>>a[i];
  }
  for(int i=0;i<((1<<h)-1);i++){
    for(int j=0;j<((1<<w)-1);j++){
      int blackn=0;
      for(int p=0;p<h;p++){
        for(int l=0;l<w;l++){
          if(((i>>p)&1)==0&&((j>>l)&1)==0&&a[p][l]=='#'){
			  blackn++;
		  }
		}
      }    
      if(blackn==k){
        re++;
	  }
    }
  }
  cout<<re<<endl;
  return 0;
}

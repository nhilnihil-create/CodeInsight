#include <iostream>
using namespace std;
main(){
  int count[4][3][10], b,f,r,v,n;
  cin >> n ;
  for( int i=0;i<4;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<10;k++){
	count[i][j][k]=0;
      }
    }
  }
  for( int i=0; i<n ; i++){
    cin >> b >> f >> r >> v ;
    count[b-1][f-1][r-1] += v;
  }
  for(b=0;b<4;b++){
    for(f=0;f<3;f++){
      for(r=0;r<10;r++){
	cout << " "  << count[b][f][r];
      }
      cout << "\n";
    }
    if(b==3)break;
    cout << "####################\n" ;
  }
}    
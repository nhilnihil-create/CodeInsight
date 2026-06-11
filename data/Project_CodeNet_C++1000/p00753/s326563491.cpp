#include<iostream>
#include<vector>
//#include<math>
using namespace std;

int main(){
  int n;
  while(cin >> n,n){
    int count = 0;
    for(int i=n+1; i <= 2*n; ++i){
      int tmp_c = 0;
      for(int j=1; j*j<= 2*n; ++j){
	if(i%j==0){++tmp_c;}
      }
      if(tmp_c==1){++count;/*cout << "sosuu is " << i << endl;*/}
    }
  
    cout << count << endl;
  }
  return 0;
}
      


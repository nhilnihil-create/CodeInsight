#include <iostream>

using namespace std;

int in,cnt;
const int coin[6] = {500,100,50,10,5,1};

int count(int* x,int y,int* c){
   *c += *x / y;
   *x  = *x % y;
}

int main(){
   while(cin >> in,in){
      cnt = 0;
      in  = 1000 - in;
      for(int i=0;i<6;i++)
	 count(&in,coin[i],&cnt);
      cout << cnt << endl;
   }
   return 0;
}
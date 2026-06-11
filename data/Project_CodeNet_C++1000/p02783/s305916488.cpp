#include <iostream>
using namespace std;

int main(){
 int H;
 int A;
 int seged=0;
 cin >> H;
 cin >> A;
 for(int i=H;i>0;i-=A){
   seged++;
 }
 cout << seged;
	return 0;
}

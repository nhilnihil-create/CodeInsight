#include <iostream>
using namespace std;
 
int main(){
	long long A,B,V,W,T;
  	cin >> A >> V >> B >> W >> T;
  	if(B>A){
  	if((A+V*T)>=(B+W*T)){cout << "YES" << endl;}
  	else{cout << "NO" << endl;}
    }
  	else{
    if((A-V*T)<=(B-W*T)){cout << "YES" << endl;}
  	else{cout << "NO" << endl;}
    }
}
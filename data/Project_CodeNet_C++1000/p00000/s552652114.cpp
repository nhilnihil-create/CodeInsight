#include <iostream>
using namespace std;
#define rep(i , m , n) for(int i=m;i<n;++i)
	
int main(){
	rep(i , 1 , 10){
		rep(j , 1 , 10){
			cout << i << 'x' << j << '=' << i*j << endl;
		}
	}
	return 0; 
}
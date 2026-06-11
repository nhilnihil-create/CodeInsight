#include <iostream>
using namespace std;

int main() {
	int n; cin>>n;
	bool band=false;
	
	for(int i=1; i<=n; i++){
		if (n%i==0){
			int aux=n/i;
			int aux2=n/aux;
			
			if(aux >= 1 && aux <=9  && aux2 >= 1 && aux2 <= 9){
				band=true;
				break;
			}
		}
	}
	string res=band ? "Yes" : "No";
	cout<<res;
	return 0;
}
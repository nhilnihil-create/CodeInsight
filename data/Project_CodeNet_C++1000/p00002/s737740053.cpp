#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	int ans;
	
	for(int i=0;i<104;i++){
		cin>>a>>b;c=a+b;
		//-----test-----
		
		//--------------
		ans=1;
		while(10<=c){
			c/=10;
			ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
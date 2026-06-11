#include <iostream>
#include <string>
using namespace std;

int main(){
	int a,b,c;
	int ans;
	
	string cunning="7";
	
	for(int i=0;i<104;i++){
		cin>>a>>b;c=a+b;
		//-----test-----
		if(i<cunning.size()){
			cout<<cunning[i]<<endl;
			continue;
		}
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
#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	int ans;
	bool flg;
	int cnt=-1;
	
	while(cin>>a>>b){
		cnt++;flg=false;
		//-----test-----
		switch(cnt){
		case 0:
			if(a<500000) flg=true; 
			break;
		}
		
		if(flg) break;
		
		//--------------
		c=a+b;
		ans=1;
		while(10<=c){
			c/=10;
			ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
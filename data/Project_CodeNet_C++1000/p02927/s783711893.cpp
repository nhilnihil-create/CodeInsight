#include <iostream>

using namespace std;

int main(){
	
	int m,d;
	cin>>m>>d;
	int d1,d10;
	int res =0;
	for(int i=22;i<=d;i++){
		d1 = i%10;
		d10=i/10;
		if(d10>=2&&d1>=2&&d1*d10<=m)res++;
	}
	cout<<res<<endl;
	
	return 0;
}
#include <iostream>
using namespace std;

const int data[6]={500,100,50,10,5,1};
int main() {
	// your code goes here
	int n;
	while(cin>>n && n){
		n=1000-n;
		int ans=0;
		for(int i=0;i<6;i++){
			ans+=n/data[i];
			n%=data[i];
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
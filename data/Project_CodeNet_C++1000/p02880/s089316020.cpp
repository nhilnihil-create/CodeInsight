#include <iostream>
using namespace std;

int main() {
	int n;
		int count=0;
	cin>>n;
	if(n>81){
	    cout<<"No"<<endl;
	}
	else if(n<1){
	    cout<<"No"<<endl;
	}

	else {
	    for(int i=1;i<=9;i++){
	        if(n%i==0){
	            if(n/i<=9&n/i>=1){
	                cout<<"Yes";
	                count=1;
	                break;
	            }
	        }
	       }
	       if(count==0)
	       cout<<"No";
	    
	}
	return 0;
}
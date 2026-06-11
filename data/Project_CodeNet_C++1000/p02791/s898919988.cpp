#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int b[n];
	cin>>b[0];
	int min=b[0],c=1;
	for(int i=1;i<n;i++){
	    cin>>b[i];
	if(b[i]<=min){
	    c++;
	    min=b[i];
	}
	    
	}
	cout<<c;
	
	
}

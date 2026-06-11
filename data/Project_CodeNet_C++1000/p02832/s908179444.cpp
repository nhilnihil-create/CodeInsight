#include <iostream>
using namespace std;

int main() {
	long long int n;
	cin>>n;
	long long int b[n];
	long int count=0,p=1;
	for(int i=0;i<n;i++){
	    cin>>b[i];
	    if(b[i]==p){
	        p++;
	    }
	    else{
	        count++;
	    }
	}
	
	if(count==n){
	    cout<<-1;
	}
	else{
	    cout<<count;
	}
	return 0;
}

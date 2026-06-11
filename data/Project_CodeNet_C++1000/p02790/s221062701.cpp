#include <iostream>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	string s1,s2;
	for(int i=0;i<n;i++){
	    s1+=m+'0';
	}
	for(int i=0;i<m;i++){
	    s2+=n+'0';
	}
	if(n<=m){
	    cout<<s2<<endl;
	}
	else if(n>m){
	    cout<<s1<<endl;
	}

}
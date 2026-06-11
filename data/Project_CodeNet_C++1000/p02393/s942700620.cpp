#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if((b<a && b<c) || (b<a && b==c)){
		swap(a,b);
	}else if((c<a && c<b) || (c<a && c==b)){
		swap(a,c);
	} 
	if(b>c){
		swap(b,c);
	}
	cout<<a<<" "<<b<<" "<<c<<endl;
	return 0;
}
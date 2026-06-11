#include <iostream>
using namespace std;
int main(void) {
	int a,b,c;
	cin>>a>>b>>c;
	if(a<b&&b<c||a<b&&b==c||a==b&&b==c){
		cout<<a<<" "<<b<<" "<<c<<endl;
	}else if(c<b&&b<a||c<b&&b==a||c==b&&b<a){
		cout<<c<<" "<<b<<" "<<a<<endl;
	}else if(b<a&&a<c||b<a&&a==c||b==a&&a<c){
		cout<<b<<" "<<a<<" "<<c<<endl;
	}else if(a<c&&c<b||a<c&&c==b||a==c&&c<b){
		cout<<a<<" "<<c<<" "<<b<<endl;
	}else if(b<c&&c<a||b<c&&c==a||b==c&&c<a){
		cout<<b<<" "<<c<<" "<<a<<endl;
	}else if(c<a&&a<b||c<a&&a==b||c==a&&a<b){
		cout<<c<<" "<<a<<" "<<b<<endl;
	}
	return 0;
}
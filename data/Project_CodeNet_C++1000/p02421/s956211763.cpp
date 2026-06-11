#include <iostream>
#include <string>
using namespace std;

int main() {
int n,t1=0,h1=0;
std::string t,h;
std::cin>>n;
while(n--){
	std::cin>>t>>h;
	if(t<h){
		h1+=3;
	}else if(t>h){
		t1+=3;
	}else{
		h1++;
		t1++;
	}
}
std::cout<<t1<<" "<<h1<<"\n";
}
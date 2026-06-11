#include<cstdint>
#include<limits>
#include<cstdbool>
#include<cmath>
#include<iostream>
#include<vector>
#include<array>
#include<list>
#include<string>
#include<sstream>
#include<algorithm>

int main(){
	int a,b,c,d;
	std::cin>>a>>b>>c>>d;
	bool flag=false;
	if(a == 4||a == 6||a == 9||a == 11){
		if(b == 30)
			flag =true;}
	else if(a == 2){
		if(b == 28)
			flag =true;}
	else{
		if(b == 31)
			flag =true;}
	std::cout<<(flag?1:0);

}

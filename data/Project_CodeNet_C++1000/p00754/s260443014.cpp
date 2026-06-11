#include<iostream>
#include<string>
#include<stack>

int main(){
	while(1){
		std::stack<char>Cstr;
		Cstr.push(' ');
		std::string str;
		int count=0;
		std::getline(std::cin,str);
		if(str==".")break;
		for(int i=0;i<str.size();i++){
			if(str[i]=='('||str[i]=='['){
				count++;
				Cstr.push(str[i]);
			}else if(str[i]==')'||str[i]==']'){
				count--;
				if(!((str[i]==')'&&Cstr.top()=='(')||(str[i]==']'&&Cstr.top()=='['))){
					std::cout<<"no"<<std::endl;
					goto end;
				}
				Cstr.pop();
			}
		}
		if(count==0)std::cout<<"yes"<<std::endl;
		else std::cout<<"no"<<std::endl;
		end:;
	}
	return 0;
}
#include<iostream>
#include<string>


int main(){
	char inp_text ='0';

	std::string text_A = "A";
	std::string text_a = "a";

	std::cin >> inp_text;

	//あえて文字列文字コードで指定Z=0x5A
	if ('A'<= inp_text && inp_text <='Z') {
		std::cout << text_A << std::endl;
		return 0;
	}
	std::cout << text_a << std::endl;
	return 0;
}

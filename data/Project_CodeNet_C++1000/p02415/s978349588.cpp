#include <iostream>
//using namespace std;

#include <stdio.h>
#include <cctype>

int main(void)
{
	std::string st;
	getline(std::cin, st);
	
	
	
	for(int i = 0 ; i < st.size();i++ ){

		char ch = st[i];
		if (std::islower(ch)){	//?°?????????????
			ch = std::toupper(ch);		//??§????????§??????
		}
		else if (std::isupper(ch)){
			ch = std::tolower(ch);
		}
		else {
			//????????????
		}
		printf("%c", ch);
	}
	printf("\n");
	return 0;
}
#include<iostream>
#include<string>
#include<stack>
// #include<string.h>

using namespace std;

int main(){
	
	
	while(1){
		
		int  i ,a=0;
		
		string str;
		stack<char> strstack;
		
		getline(cin , str);
		
		if(str[0] == '.') return 0;
		
		for(i=0 ; i<100  ; i++){
			
// 		cout << str[i] << endl;
			
			if (str[i] == '.') break;
			
			else if (str[i] == '['){
				
//				printf("[の読み込み\n");
					
				strstack.push(str[i]);
				
			}
					
			else if (str[i] == '('){
				
//				printf("(の読み込み\n");
				strstack.push(str[i]);
				
			}
			
			else if (str[i] == ']'){
//				printf("]の読み込み\n");
				if( strstack.empty() ) {
					a = 1;
					break;
					
				}
				else {
					
					if(strstack.top() == '['){
						strstack.pop();
					}
					else {
						a = 1;
						break;
					}
				}
			
			}
			
			else if (str[i] == ')'){
//				printf(")の読み込み\n");
				if( strstack.empty() ){
					a = 1;
					 break;
				}
				else {
					
					if(strstack.top() == '('){
						strstack.pop();
					}
					else {
						a = 1;
						break;
					}
				}
			
			}
	
		}
		

		
		if(a==0 && strstack.empty() == 1)  {
			
			printf("yes\n");
			
		}
		else printf("no\n");
			 
	}
	
	
	return 0;
			
	
	

	
}
#include <bits/stdc++.h>
using namespace std;
int main(void){
	char c;
	while(1){
    	scanf("%c",&c);
    	if(isalpha(c) ){
    		if("%c",isupper(c) ) printf("%c", tolower(c));
    		else if("%c",islower(c) )printf("%c", toupper(c));
    	}else printf("%c", c);

    	if(c == '\n') break;
	}
    return 0;
}

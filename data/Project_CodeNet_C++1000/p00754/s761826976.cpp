#include<iostream>

char c[3] = ")]";

bool search(char* s,int* i){
	int b = 0;
	if(s[(*i)] == '[')
		b = 1;
	for((*i)++; s[(*i)] != '.'; (*i)++){
		if(s[(*i)] == c[b])
			return true;
		else if(s[(*i)] == c[1-b])
			return false;
		else if(s[(*i)] == '(' || s[(*i)] == '[')
			if(!search(s, i))
				return false;
	}
	return false;
}

int main(){
	using std::cout;
	char input[128];
	int i;
	for(;;){
		std::cin.getline(input, sizeof(input));
		if(input[0] == '.')
			return 0;
		for(i=0; input[i] != '.'; i++){
			if(input[i] == '(' || input[i] == '['){
				if(!search(input, &i))
					goto NO;
			}else if(input[i] == ']' || input[i] == ')')
				goto NO;
		}
		std::cout << "yes\n";
		continue;
NO:;
		std::cout << "no\n";
	}
}
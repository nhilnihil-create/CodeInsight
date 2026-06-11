#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>

using namespace std;

int search(int i, char c);

char str[200];
int l;

int main()
{
	while(1){
		fgets(str, sizeof(str), stdin);
		if(str[0] == '.') break;
		int ans = 1;
		l = strlen(str);
		for(int i = 0; i < l; i++){
			if(str[i] == '(' || str[i] == '['){
				ans = search(i, str[i]);
				if(ans == 0) break;
			} else if(str[i] == ')' || str[i] == ']'){
				ans = 0;
				break;
			}
		}
		if(ans == 1) cout << "yes" << endl;
		else if(ans == 0) cout << "no"<< endl;
	}
	return 0;
}

int search(int i, char c)
{
	if(i == l-2) return 0;
	char d, e;
	if(c == '('){
		d = ')';
		e = ']';
		}else if(c == '['){
			d = ']';
			e = ')';
		}
		str[i] = '0';
	for(int j = i+1; j < l; j++){
		if(str[j] == '(' || str[j] == '['){
			if(search(j, str[j]) == 0) return 0;
			else continue;
		} else if(str[j] == d){
			str[j] = '0';
			return 1;
		} else if(str[j] == e){
			str[j] = '0';
			return 0;
		}
	}
	return 0;
}
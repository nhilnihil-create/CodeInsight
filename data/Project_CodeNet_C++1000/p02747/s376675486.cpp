#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
	string s;
	cin >> s;
	if (s.size() % 2 == 1){
		printf("No\n");
		return 0;
	}
	for (int i = 0; i < s.size(); i += 2){
		if (s[i] != 'h' || s[i + 1] != 'i'){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}
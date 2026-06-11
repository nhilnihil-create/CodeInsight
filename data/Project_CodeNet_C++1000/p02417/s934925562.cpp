#include<iostream>
#include<string>
using namespace std;
int main(){
	char ch;
	int counter[26];
	for(int i =0;i<26;i++){
		counter[i] = 0;
	}
	while(cin >> ch){
			ch = tolower(ch);
			int num = ch - 'a';
			counter[num]++;
	}

	for(int i = 0 ; i < 26 ; i++){
		int num = i + 'a';
		cout << (char)num << " "<<":"<<" " << counter[i] <<endl;
	}


	return 0;
} 
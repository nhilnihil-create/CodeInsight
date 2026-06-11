#include<iostream>
#include<string>
using namespace std;

int main(){
	char ch, ch2, ch3;
	int num;
	int counter[26] = {0};
	
	while ( cin >> ch ){
    	ch2 = tolower(ch);
		num = ch2 - 'a';
		
		counter[num]++;
		
	}
	
	for(int i=0; i<26; i++){
		ch3 = 'a' + i;
		cout << ch3 << " : " << counter[i] << endl;
	}
		
 	return 0;
}
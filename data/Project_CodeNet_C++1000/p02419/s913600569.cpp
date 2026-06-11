#include <iostream>
#include <string>

using namespace std;

int main(){
	int count=0;
	string W,word;
	cin >> W;
	int size=W.size();
	for(int i=0;i<size;i++){
		W[i]=toupper(W[i]);
	}
	while(1){
		cin >> word;
		if(word == "END_OF_TEXT") break;
		int size=word.size();
		for(int i=0;i<size;i++){
			word[i]=toupper(word[i]);
		}
		if(word == W) count++;
	}
	cout << count << endl;
	return 0;
}
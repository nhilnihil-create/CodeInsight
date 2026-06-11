#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

//10進数1桁の文字を整数型にする
int toInt(char c){
	return c - '0';
}

int main(){
	const char buttonTable[10][5]={{},//確定ボタン　0
							{'.', ',' ,'!', '?', ' '},//1 (5)
							{'a','b','c'},//2 (3)
							{'d','e','f'},//3 (3)
							{'g','h','i'},//4 (3)
							{'j','k','l'},//5 (3)
							{'m','n','o'},//6 (3)
							{'p','q','r','s'},//7 (4)
							{'t','u','v'},//8 (3)
							{'w','x','y','z'}};//9(4)
	const int bsize[10] = {0,5,3,3,3,3,3,4,3,4};//ボタンの文字の種類
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		char command[1025];//char command[1025];
		cin >> command;
		int len = strlen(command);
		char result[76];//作ったメッセージ。サイズは[1,76) \0を忘れずに
		int idx = 0;//resultの入力場所
		int row=0;//ボタンを押した場所。表の行(row)
		int col=0;//同じボタンを押した回数。表の列(column)
		for(int j=0;j<len;j++){
			int button = toInt(command[j]);
			if(button == 0){
				if(row != 0){//文字を入力できる
					result[idx] = buttonTable[row][col];
					idx++;
					row = 0;
					col = 0;
				}
			}else if(button == row){
				col = (col+1)%bsize[button];
				
			}else{//文字を決定した次のコマンド
				row = button;
				//colの値は必ず0
			}
		}
		//result[idx] = '\0';
		//cout << idx << endl;
		//cout <<result << endl;
		for(int i=0;i<idx;i++){//文字列はidx文字ある
			cout << result[i];
		}
		cout << endl;
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(void){
	//FILE* fp_in = freopen("data.txt", "r", stdin);
	string ans[] = {"yes", "no"};

	while(1) {
		int flg = 0;
		string s;
		getline(cin, s);
		if( s == "." ) break;
		int paren = 0;
		int brack = 0;
		vector<int> type;
		for(int i = 0; i < s.length(); i++) {
			char ch;
			ch = s.at(i);
			switch(ch) {
				case '(':
					type.push_back(1);
					paren ++;
					break;
				case ')':
					if(type.size() == 0) {
						flg = 1;
					} else {
						if(type.back() != 1) flg = 1;
						else type.pop_back();
					}
					paren --;
					break;
				case '[':
					type.push_back(2);
					brack ++;
					break;
				case ']':
					if(type.size() == 0) {
						flg = 1;
					} else {
						if(type.back() != 2) flg = 1;
						else type.pop_back();
					}
					brack --;
					break;
				default:
					break;
			}
			if( paren < 0 || brack < 0 ) flg = 1;
		}
		if(paren != 0 || brack != 0) flg = 1;
		cout << ans[flg] << endl;

	}

	
	//while(1){}
	return 0;
}
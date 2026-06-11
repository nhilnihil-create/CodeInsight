#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

string str;

bool input(){
		getline(cin,str);
		return str != ".";
}

void solve(){
//	cout << str <<endl;
	int maru=0;
	int kaku=0;
	char flag;
	int count = 0;
	char lst[101];
	for(int i = 0; i < (int)str.size();i++){
			char c =str[i];
			if(c == '('){
					maru++;
					lst[count]='(';
					count++;
					//flag = ')';
			}
			if(c == '['){
					kaku++;
					lst[count] = '[';
					count++;
					//flag = ']';
			}
			if(c == ')'){
					if(maru <= 0 || lst[count-1] !='('){
							cout << "no"  << endl;
							return;
					}
					
					maru --;
					count--;
			}
			if(c == ']'){
					if(kaku <= 0 || lst[count-1] != '['){
							cout << "no" << endl;//c << endl;
							return;
					}
					kaku--;
					count--;
			}
	}
	if(maru == 0 && kaku == 0)cout << "yes" <<endl;
	else cout << "no" <<endl;
}

int main(){
		while(input())solve();
}


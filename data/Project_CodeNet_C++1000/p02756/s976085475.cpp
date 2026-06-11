#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
using namespace std;

int main(){
	deque<char> de;
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		de.push_back(s.at(i));
	}
	int q;
	cin >> q;
	int tcnt = 0;
	for(int i=0;i<q;i++){
		int t;
		cin >> t;
		if(t == 1){
			tcnt++;
			continue;
		}
		int f;
		char c;
		cin >> f;
		cin >> c;
		if(tcnt % 2 == 0){
			if(f == 1){
				de.push_front(c);
			}else{
				de.push_back(c);
			}
		}else{
			if(f == 1){
				de.push_back(c);
			}else{
				de.push_front(c);
			}
		}
	}
	if(tcnt % 2 != 0){
		reverse(de.begin(),de.end());
	}
	for(char x: de){
		cout << x;
	}
	cout << endl;
	return 0;
}

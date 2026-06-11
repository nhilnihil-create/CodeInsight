#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
typedef map<string, void(*)> funcs_type;

void print(string &s, int a, int b){
	if(a < 0 || a > b || b > s.size()) return;
	for(int i = a; i <= b; i++)
		cout << s[i];
	cout << endl;
}

void reverse(string &s, int a, int b){
	if(a < 0 || a > b || b > s.size()) return;
	for(int i = a, j = b; i < j; i++, j--)
		swap(s[i], s[j]);
}

void replace(string &s, int a, int b, string p){
	if(a < 0 || a > b || b > s.size()) return;
	if(b - a + 1 != p.size()) return;
	for(int i = 0; i < b-a+1; i++)
		s[a+i] = p[i];
}

int main(){
	string str, cmd, p;
	int n, a, b;
	cin >> str;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> cmd;
		if(cmd == "print"){
			cin >> a >> b;
			print(str, a, b);
		}
		if(cmd == "reverse"){
			cin >> a >> b;
			reverse(str, a, b);
		}
		if(cmd == "replace"){
			cin >> a >> b >> p;
			replace(str, a, b, p);
		}
	}
	return 0;
}
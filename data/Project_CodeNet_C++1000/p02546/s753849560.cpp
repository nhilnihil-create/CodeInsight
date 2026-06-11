#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;



int main(){
	string str;
	cin >> str;

	char last = str[str.size()-1];

	cout << str;
	if(last == 's') cout << "es" << endl;
	else cout << "s" << endl;
}

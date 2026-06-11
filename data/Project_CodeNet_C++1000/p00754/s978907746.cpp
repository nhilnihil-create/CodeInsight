#include"iostream"
#include"fstream"
#include"stack"
#include"string"

using namespace std;

int main(){

	//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1173&lang=jp

	ifstream fin;
	ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	//http://www.cppll.jp/cppreference/cppstack_details.html
	//empty()関数は現在のスタックが空の時にtrueを返し、そうでないときはfalseを返す 

	string a;

	stack<char> s;
	bool yes = true;

	while (true){
		yes = true;

		getline(cin, a);

//		cout << a << endl;

//		if (a[0] == ' ')
//			cout << "ファーーーwww" << endl;
		if (a[0] == '.')break;

		for (int i = 0; i < 100; i++){
			if (a[i] == '(' || a[i] == '['){
				s.push(a[i]);
				yes = false;
			}
			if (a[i] == ')'){
				if (!s.empty()){
					if (s.top() == '('){
						yes = true;
						s.pop();
					}
					else {
						yes = false;
						break;
					}
				}
				else {
					yes = false;
					break;
				}
			}
			if (a[i] == ']'){
				if (!s.empty()){
					if (s.top() == '['){
						yes = true;
						s.pop();
					}
					else {
						yes = false;
						break;
					}
				}
				else {
					yes = false;
					break;
				}
			}
			//			if (!s.empty())
			//				cout << a[i] << "  :  " << s.top() << "  :  " << yes << endl;
			//			else cout << "topエラー" << endl;
			if (a[i] == '.')break;
		}
		if (!s.empty())yes = false;
		while (!s.empty())s.pop();
		if (yes == true){
//			cout << "yes" << endl;
			fout << "yes" << endl;
		}
		else{
//			cout << "no" << endl;
			fout << "no" << endl;
		}
	}
	return 0;
}
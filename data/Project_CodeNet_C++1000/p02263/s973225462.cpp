#include <string>
#include <stack>
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
  string word;
  stack<int> S;
  while (cin >>word) { //入力がある限り読み込む
    if (word =="+") {
	  //数を二つpopして、和をpushする
	   int a = S.top();
	  S.pop();
	  int b = S.top();
	  S.pop();
	  S.push(b + a);
	  }
	else if (word =="-") {
	  //数を二つpopして、差をpushする
	  int a = S.top();
	  S.pop();
	  int b = S.top();
	  S.pop();
	  S.push(b - a);
	  }
	else if (word == "*") {
	  //数を二つpopして、席をpushする
	   int a = S.top();
	  S.pop();
	  int b = S.top();
	  S.pop();
	  S.push(b * a);
	  }
	else {
	  //wordを数値にしてpushする
	  int n = atoi(word.c_str());
	  S.push(n);
	  }
	 }
	//Sの先頭要素を表示する
	cout << S.top() << endl;
	}
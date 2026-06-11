#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string hantei(string line);

int main(void){
	string line;
	vector<string> result;
	while (getline(cin, line)){
		if (line == "."){
			return 0;
			//break;
		}
		cout << hantei(line) << endl;
		//result.push_back(hantei(line));
	}
	/*
	vector<string>::iterator it = result.begin();
	while( it != result.end()){
	cout << *it << endl;
	++it;
	}
	*/
	return 0;
}

string hantei(string line){
	stack<char> left;
	stack<char> right;

	for (int i=0; i<line.size(); ++i){
		if ((line[i] == '(') || (line[i] == '[')){
			left.push(line[i]);
		}
		if ((line[i] == ')') || (line[i] == ']')){
			right.push(line[i]);
		}
		if (!left.empty()){
			if ((left.top() == '(') && (line[i] == ')')){
				left.pop();
				right.pop();
			}
			else if ((left.top() == '[') && (line[i] == ']')){
				left.pop();	
				right.pop();
			} 
		}
	}
	if (left.empty() && right.empty()){
		return "yes";
	}
	else{
		return "no";
	}
}
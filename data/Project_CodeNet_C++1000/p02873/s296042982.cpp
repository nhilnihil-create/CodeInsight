#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector <int> vec;

long long calc(){
	long long res = 0; 
	for(int i = 0; i < vec.size(); i++){
		res += vec[i];
	}
	return res; 
}

void solution(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '<')
			vec[i+1] = vec[i] + 1; // Since <, next has to be greater
  }

	for(int i = s.size()-1; i >= 0; i--){
		if(s[i] == '>')
			vec[i] = max(vec[i], vec[i+1]+1);
	}

	cout << calc() << endl;
}

int main(){
	string s;
	cin >> s;

	// Set everything in the vector to 0
	for(int i = 0; i < s.size()+1; i++)
		vec.push_back(0);

	solution(s);
}
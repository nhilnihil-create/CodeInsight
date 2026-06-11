#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
int main(){
	string line;
	getline(cin, line);
	stringstream ss;
	ss << line;
	string s;
	map<string, int> cnt;
	string maxLengthString = "";
	pair<int, string> maxEncount(0,"");
	while(ss >> s){
		cnt[s]++;
		if( maxLengthString.size() < s.size()) maxLengthString = s;
		if(maxEncount.first < cnt[s]){
			maxEncount = make_pair<int,string>(cnt[s],s);
		}
	}
	cout << maxEncount.second << " " << maxLengthString << endl;
	return 0;
}
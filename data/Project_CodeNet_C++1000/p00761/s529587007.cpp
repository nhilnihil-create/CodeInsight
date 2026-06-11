#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string itos(int t){
	ostringstream oss; oss << t;
	return oss.str();
}

int stoi(string str){
	istringstream iss(str);
	int t; iss >> t;
	return t;
}

int getNext(int a, int L){
	string s = itos(a);
	while(s.size() < L) s += "0";
	sort(s.begin(), s.end());
	int m = stoi(s);
	reverse(s.begin(), s.end());
	int M = stoi(s);
	return M-m;
}

int main(){
	int a0, L;
	while(cin >> a0 >> L, L){
		vector<int> a; a.push_back(a0);
		bool end = false;
		while(true){
			int next = getNext(a.back(), L);
			for(int i=0;i<a.size();i++)
				if(a[i] == next){
					end = true;
					cout << i << " " << a[i] << " " << a.size()-i << endl;
					break;
				}
			if(end) break;
			a.push_back(next);
		}
	}
}
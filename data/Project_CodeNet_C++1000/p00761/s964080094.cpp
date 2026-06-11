#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(){
	string s;
	int L;
	while(cin >> s >> L, s != "0", L){
		string zero;
		for(int i = 0; i < L - s.size(); i++) zero += "0";
		s = zero + s;
		int n = atoi(s.c_str());
		vector<int> slist;
		int i = 0;
		do{
			slist.push_back(n);
			string smax, smin;
			sort(s.begin(), s.end());
			smin = s;	
			sort(s.begin(), s.end(), greater<char>());
			smax = s;
			int imax = atoi(smax.c_str()), imin = atoi(smin.c_str());
			n = imax - imin;
			ostringstream os;
			os << n;
			s = os.str();
			zero = "\0";
			for(int i = 0; i < L - s.size(); i++) zero += "0";
			s = zero + s;
		}while(find(slist.begin(), slist.end(), n) == slist.end());
		int I;
		for(int i = 0; i < slist.size(); i++) if(slist[i] == n) I = i;
		cout << I << " " <<  atoi(s.c_str()) << " " << slist.size() - I << endl;
	}

	return 0;
}
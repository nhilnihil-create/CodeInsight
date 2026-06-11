#include <cstdio>
#include <cstdlib>
//#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>
using namespace std;

int main(void){
	
	int n; cin >> n;

	for (int i = 0; i < n; i++){
		set<string> result;
		result.clear();

		string str;
		cin >> str;


		for (int j = 1; j < str.size(); j++){
			string sub1 = str.substr(0, j);
			string sub2 = str.substr(j, str.size() - j);

			result.insert(sub1 + sub2);
			result.insert(sub2 + sub1);
			reverse(sub1.begin(), sub1.end());
			result.insert(sub1 + sub2);
			result.insert(sub2 + sub1);
			reverse(sub2.begin(), sub2.end());
			result.insert(sub1 + sub2);
			result.insert(sub2 + sub1);
			reverse(sub1.begin(), sub1.end());
			result.insert(sub1 + sub2);
			result.insert(sub2 + sub1);
		}

		cout << result.size() << endl;
	}

	return 0;
}
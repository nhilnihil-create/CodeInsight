#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> keys;
	while(n--){
		int buf;
		cin >> buf;
		keys.push_back(buf);
	}
	
	for(int i = 1; i <= keys.size(); i++){
		cout << "node " << i << ": key = " << keys[i-1] << ", ";
		if(i/2 > 0) cout << "parent key = " << keys[i/2-1] << ", ";
		if(i*2 <= keys.size()) cout << "left key = " << keys[i*2-1] << ", ";
		if(i*2+1 <= keys.size()) cout << "right key = " << keys[i*2] << ", ";
		cout << endl;
	}
	
	return 0;
}
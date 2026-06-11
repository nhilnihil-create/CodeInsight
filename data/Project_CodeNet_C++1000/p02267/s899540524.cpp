#include <iostream>
#include <set>
using namespace std;

int main(){
	int n;
	cin >> n;
	set<string> data1;
	string tmp;
	while(n--){
		cin >> tmp;
		data1.insert(tmp);
	}		
	int m;
	cin >> m;
	int count = 0;
	while(m--){
		cin >> tmp;
		if(data1.find(tmp) != data1.end()) count++;
	}
	cout << count << endl;
	return 0;
}
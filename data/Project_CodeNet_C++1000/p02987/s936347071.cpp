#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool flag = 0;
string arr;
vector<char> v;

int main() {
	
	cin >> arr;
	
	if (arr[0] == arr[1]){
		if(arr[2] == arr[3] && arr[2] != arr[0])	cout << "Yes";
		else	cout << "No";
	}
	else if (arr[0] == arr[2]){
		if(arr[1] == arr[3] && arr[1] != arr[0])	cout << "Yes";
		else	cout << "No";
	}
	else if (arr[0] == arr[3]){
		if(arr[2] == arr[1] && arr[2] != arr[0])	cout << "Yes";
		else	cout << "No";
	}
	else cout << "No";
	
	return 0;
}
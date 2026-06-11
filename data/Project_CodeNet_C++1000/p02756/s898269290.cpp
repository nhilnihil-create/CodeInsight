#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s;
	char C;
	vector<vector<char>> a(2,vector<char>());
	int front=0,Q,T,F;

	cin >> s;
	cin >> Q;

	for(int i = 0;i < Q;i++){
		cin >> T;
		if(T == 1) front= (front+1)%2;
		else{
			cin >> F >> C;
			a[(front + F - 1)%2].push_back(C);
		}
	}

	if(front == 1) reverse(s.begin(),s.end());
	reverse(a[front].begin(),a[front].end());
	
	for(char c:a[front])
		cout << c;
	cout << s;
	for(char c:a[(front+1)%2])
		cout << c;
	cout << endl;

	return 0;
}
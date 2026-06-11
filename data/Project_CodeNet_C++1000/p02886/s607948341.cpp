#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> d(n);
	int i,s,count = 0;
	for(i = 0;i < n;i++)cin >> d.at(i);
	for(i = 0;i < n-1;i++){
		for(s = i+1;s < n;s++){
			count += d.at(i) * d.at(s);
		}
	}
	cout << count << endl;
}
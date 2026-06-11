#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int i = 0;
	int count = 0;
	while(s[i]!='\0'){
		if (s[i] != t[i])
			count++;
		i++;
	}
	cout << count << endl;
	return 0;
}
#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

int main(){
	string arr[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	string s;
	cin >> s;
	rep(i, 7) {
		if(s == arr[i]) {
			cout << 7 - i << endl;
			return 0;
		}
	}
}
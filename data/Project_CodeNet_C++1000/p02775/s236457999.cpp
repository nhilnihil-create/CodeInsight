
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int cur = 0;
	int used = 0;
	for(int i = s.length() - 1; i >= 0; --i){
		int num = s[i] - '0';
		num += cur;
		// cout <<"num: " <<num;
		if(num == 5 && i > 0 && s[i - 1] >= '5'){
			cur = 1, used += 5, s[i - 1] = s[i - 1];
			//cout << s[i - 1] <<" ";
			continue;
		}

		if(num > 5){
			used += 10 - num;
			// s[i] = '0';
			cur = 1;
		}
		else{
			cur = 0;
			// s[i] = num + '0';
			used += num;
		}
	}
	// cout << cur <<"\n";
	// cout << used;
	if (cur == 1) used ++;
	cout << used;
}



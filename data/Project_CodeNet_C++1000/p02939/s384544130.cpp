#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	string s;
	cin >> s;
	int cnt = 0;
	int i = 1;
	rep(i, s.size()){
		if(i == s.size() - 1) cnt++;
		else if(s[i] == s[i+1]){
			if(i == s.size() - 2){
				cnt++;
				break;
			}else{
				cnt += 2;
				i += 2;
			}
		}else{
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
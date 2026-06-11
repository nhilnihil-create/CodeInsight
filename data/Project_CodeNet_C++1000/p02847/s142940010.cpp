#include <bits/stdc++.h>
#define PI 3.141592653589793
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	string S;
	int i,k;
	int ans=0;
	int ctr=0;

	cin >> S;

	if(S=="SUN")
		cout << 7 << endl;
	if(S=="MON")
		cout << 6 << endl;
	if(S=="TUE")
		cout << 5 << endl;
	if(S=="WED")
		cout << 4 << endl;
	if(S=="THU")
		cout << 3 << endl;
	if(S=="FRI")
		cout << 2 << endl;
	if(S=="SAT")
		cout << 1 << endl;

	return 0;
}



#include <bits/stdc++.h>
using namespace std;

long long d[10][10];

int main() {
	long long n;
	cin >> n;
	for(long long i=1;i<=n;i++){
		long long a,b;
		b=i%10;
		string str = to_string(i);
		a=str[0]-'0';
		d[a][b]++;
	}
	long long res=0;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			res += d[i][j]*d[j][i];
		}
	}
	cout << res << endl;
}

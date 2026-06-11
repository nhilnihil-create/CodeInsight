#include <iostream>
using namespace std;
#define MAX 300000

int a[MAX];
long long s[MAX];
int main(){
	fill(a, a+MAX, 1);
	for(int i = 2;i < MAX;i++){
		if(a[i]){
			for(int j = 2;i*j < MAX;j++)a[i*j] = 0;
		}
	}
	s[1] = 0;
	for(int i = 2;i < MAX;i++)s[i] = s[i-1]+a[i];
	int n, ans;
	while(cin >> n, n){
		ans = s[2*n]-s[n+1];
		if(s[n] != s[n+1])cout << ans+1 << endl;
		else cout << ans << endl;
	}
	return 0;
}
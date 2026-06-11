#include <iostream>
using namespace std;

const int max_data = 4;
int x;
int n=0;
int ans;

void solve(int n, int x)
{
	if(x > max_data*9){
		return;
	}

	if(n == max_data && x==0){
		ans++;
		return;
	}else if(n == max_data){
		return;
	}

	for(int i=0;i<=9;i++){
		if(x-i >= 0){
			solve(n+1,x-i);
		}
	}
	return;
}

int main()
{
	while(cin >> x){
		ans = 0;
		solve(n,x);
		cout << ans << endl;
	}
	return 0;
}
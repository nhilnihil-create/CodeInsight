#include <bits/stdc++.h>

using namespace std;

int main(){
	long long k;
	cin >> k;
	if(k%2==0 || k%5==0){
		return cout << "-1\n",0;
	}
	int cur=7%k;
	int ans=1;
	while(cur!=0){
		cur=cur*10+7;
		cur%=k;
		ans++;
	}
	cout << ans << endl;
}

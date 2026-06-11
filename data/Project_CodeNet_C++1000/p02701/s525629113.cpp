#include<bits/stdc++.h>
using namespace std;

map<string,bool> cek;

int main(){
	int n,ans=0;
	cin >> n;
	while(n--){
		string x;
		cin >> x;
		if (!cek[x]){
			cek[x]=1;
			ans++;
		}
	}
	cout << ans << '\n';
}
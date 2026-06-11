#include<bits/stdc++.h>
using namespace std;

//var 
int n,k,s;

int main(){
	cin >> n >> k >> s;
	for(int i = 1; i<=k; i++){
		cout << s << " ";
	}
	for(int i = k+1; i<=n; i++){
		cout << (s==1e9?1:s+1) << " ";
	}cout << endl;
}
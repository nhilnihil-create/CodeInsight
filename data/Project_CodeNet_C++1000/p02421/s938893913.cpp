#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int as=0,bs=0;
	for(int i=0;i<n;i++){
		string a,b;
		cin >> a >> b;
		if(a>b) as+=3;
		else if(a<b) bs+=3;
		else {
			as++;
			bs++;
		}
	}
	cout << as << " " << bs << endl;
	return 0;
}
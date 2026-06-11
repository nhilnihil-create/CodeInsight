#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=1; i<57572; i++){
		if((i*n)%360==0){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
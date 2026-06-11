#include <bits/stdc++.h>

using namespace std;

int main(){
	while(true){
	int n;
	cin >> n;
	if(n==0)break;
	vector<int> list(n,0);
	double ave=0;
	for(int z=0;z<n;z++){
		cin >> list[z];
		ave += (double)list[z];
	}
	ave /= n;
	double a=0;
	for(int i=0;i<n;i++){
		a += pow(list[i]-ave,2.0);
	}
	a /= n;
	printf("%f\n",sqrt(a));
	}
	return 0;
}
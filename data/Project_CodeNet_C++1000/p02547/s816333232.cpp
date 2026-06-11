#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,i,count =0;
	int d1[100],d2[100];
	bool result = false;
	cin >> n;
	for (i=0; i < n; i++){
		cin >> d1[i] >> d2[i];
	}
	for (i=0; i < n; i++){
		if (d1[i] == d2[i]){
			count++;
		}
		else count = 0; 
		if ( count == 3) result = true;		
	}
	if (result == true ) cout << "Yes";
	else cout << "No";
	return 0;
}

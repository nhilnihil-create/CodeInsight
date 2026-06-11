#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

int main() {
	IOS;
	long long int n; 
	cin >> n;
	
	vector<long long> A(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	long long int nein = 1;
	bool flag = false;
	
	for(int i = 0; i < n; i++){
		if(A[i] == nein){
			nein++;
			flag = true;
		}
	}
	if(flag){
		cout << n - nein + 1 << endl;
	}
	else{
		cout << -1 << endl;
	}
    return 0;
}
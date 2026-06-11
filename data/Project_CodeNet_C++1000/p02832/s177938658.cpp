#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	int m = 0;
	for(int i=0;i<n;i++){
		if(a[i]==m+1){
			m++;
		}
	}
	if(m==0){
		cout << "-1" << endl;
	}else{
		cout << n-m << endl;
	}

	

	return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define M 1000000007
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin >> n;
	int a[n+1]={0};
	for(int i=0;i<n-1;i++){
		int num;
		cin >> num;
		a[num]++;
	}
	for(int i=0;i<n;i++){
		cout << a[i+1] << endl;
	}
} 
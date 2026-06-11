#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	int n,k;
	cin >> n >> k;

	vector<ll> a(n);
	for(int i=0;i<n;i++) cin >> a[i];

	for(int i=k;i<n;i++){
		if(a[i-k]<a[i]){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}

	return 0;
}

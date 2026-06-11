#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	int n,m;
	int a[1000];

	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];

	sort(a,a+n);
	reverse(a,a+n);

	int sum = 0;
	for(int i=0;i<n;i++) sum += a[i];

	int r = 0;
	for(int i=0;i<n;i++) if(a[i]*4*m>=sum) r++;

	if(r<m){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}

	return 0;
}

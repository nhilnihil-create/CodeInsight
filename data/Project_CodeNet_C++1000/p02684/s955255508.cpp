#include <bits/stdc++.h>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	int n,k;
	cin >> n >> k;
	
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		a[i]--;
	}

	int cnt[n]={0};
	int p = 0;
	int l = 0;
	int r = 0;
	for(int i=0;i<k;i++){
		cnt[p]++;
		if(cnt[p]==2 && l==0){
			l = i;
		}
		if(cnt[p]==3){
			l = i - l;
			r = (k-i) % l;
			break;
		}
		p = a[p];
	}
	for(int i=0;i<r;i++){
		p = a[p];
	}
	
	cout << p+1 << endl;
	return 0;
}
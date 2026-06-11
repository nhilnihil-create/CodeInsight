/****Author: ABHIMANYU****/
#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	int ar[110];
	for(int i=0;i<n;i++){
		cin >> ar[i];
	}
	sort(ar,ar+n);
	
	int count=0;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<n;j++){
			if(ar[i]==ar[j]){
				continue;
			}
			for(int k=j+1;k<n;k++){
				if(ar[j]== ar[k]){
					continue;
				}
				count += ar[i] + ar[j] > ar[k];
			}
		}
	}
	cout << count << endl;
}


int main(){
/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif*/
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
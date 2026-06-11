#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

int main(){	
	
	int n;
	cin >> n;
	
	vector<int> l(n);
	for(int i=0;i<n;i++)cin >> l[i];
	sort(l.begin(),l.end());
	int ans=0;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			int k=l[i]+l[j];
			for(int x=j+1;x<n;x++){
				if(k>l[x]){
					ans++;
				}else{
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

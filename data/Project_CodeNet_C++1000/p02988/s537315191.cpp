#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,ans=0; cin>>n;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin>>arr[i];
	}
	for(int i=1; i<n-1; i++){
		set<int> s;
		s.insert(arr[i]); s.insert(arr[i+1]); s.insert(arr[i-1]); 
		if(*(++s.begin()) == arr[i])ans++;
	}
	cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int counter[1000006];
bool divided[1000005];
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	sort(arr.begin(),arr.end());
	for(int i=0; i<n; i++){
		counter[arr[i]]++;
		if(!divided[arr[i]] && counter[arr[i]]==1){
			for(int j=2*arr[i]; j<=1000000; j+=arr[i]) divided[j] = true;
		}
	}
	int ret = 0;
	for(int i=0; i<n; i++){
		if(arr[i]==1){
			if(counter[1]==1) ret++;
		}
		else{
			if(counter[1]) continue;
			if(divided[arr[i]] || counter[arr[i]]>1) continue;
			ret++;
		}
	}
	cout<<ret;
}

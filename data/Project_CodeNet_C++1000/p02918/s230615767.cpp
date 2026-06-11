#include <bits/stdc++.h>

using namespace std; 
 
#define int long long
#define M 1000000007 
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
//	int t;
//	cin >> t;
//	while(t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		string s1=s;
		int ans=0;
		vector<pair<int,int> > arr;
		for(int i=0;i<n;i++){
			if(s[i]=='L'){
				int cnt=0,ind=i;
				while(i<n&&s[i]=='L'){
					i++;
					cnt++;
				}
				int temp=cnt;
				if(ind-1>=0){
					cnt++;
				}
				if(i==n){
					cnt--;
				}
				arr.push_back(make_pair(cnt-temp-1,ind));
			}
		}
		sort(arr.begin(),arr.end(),greater<pair<int,int> >());
		for(int i=0;i<min(k,(int)arr.size());i++){
			int j=arr[i].second;
//			cout << "j " << j << " cnt " << arr[i].first << endl;
			while(j<n&&s[j]=='L'){
				s[j]='R';
				j++;
			}
		}
		for(int i=0;i<n-1;i++){
			if(s[i+1]==s[i]){
				ans++;
			}
		}
		s=s1;
		int tans=ans;
		ans=0;
		arr.clear();
		for(int i=0;i<n;i++){
			if(s[i]=='R'){
				int cnt=0,ind=i;
				while(i<n&&s[i]=='R'){
					i++;
					cnt++;
				}
				int temp=cnt;
				if(ind-1>=0){
					cnt++;
				}
				if(i==n){
					cnt--;
				}
				arr.push_back(make_pair(cnt-temp-1,ind));
			}
		}
		sort(arr.begin(),arr.end(),greater<pair<int,int> >());
		for(int i=0;i<min(k,(int)arr.size());i++){
			int j=arr[i].second;
//			cout << "j " << j << " cnt " << arr[i].first << endl;
			while(j<n&&s[j]=='R'){
				s[j]='L';
				j++;
			}
		}
		for(int i=0;i<n-1;i++){
			if(s[i+1]==s[i]){
				ans++;
			}
		}
		cout << max(tans,ans) << endl;
//	}
}
 
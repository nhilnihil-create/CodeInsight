#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(v[i]+v[j]>v[k] && v[i]!=v[j] && v[j]!=v[k]){
//					cout<<v[i]<<' '<<v[j]<<' '<<v[k]<<endl;
					ans++;
				}
//				if(v[i]+v[j]==v[k] || v[i]==v[j] || v[j]==v[k]) continue;
//				cout<<v[i]<<' '<<v[j]<<' '<<v[k]<<endl;
//				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
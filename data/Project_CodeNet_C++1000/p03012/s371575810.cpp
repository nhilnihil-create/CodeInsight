#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sidha(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int> 
#define pb push_back

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int n;cin>>n;
	int arr[n];
	ll sum=0,c=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	ll m=INT_MAX;
	for(int i=0;i<n;i++){
		c+=arr[i];
		int x=sum-c;
		m=min(abs(x-c),m);
	}
	cout<<m<<endl;
	return 0;
}
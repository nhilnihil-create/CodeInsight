#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define first F
#define second S
typedef long long ll;

int main(){
	int n; cin>>n;
	n-=1;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	ll rta = arr[0] + arr[n-1];
	for(int i=n-1; i>0; i--){
		rta+=min(arr[i], arr[i-1]);
	}
	cout<<rta<<endl;
}

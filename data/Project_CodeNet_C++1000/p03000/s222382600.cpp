#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n,m; cin>>n>>m;
    int arr[n];
    cin>>arr[0];
    for(int i=1; i<n; i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	int b=1;
	for(int i=0; i<n; i++){
		if(arr[i]<=m)b++;
	}
	cout<<b<<endl;
}

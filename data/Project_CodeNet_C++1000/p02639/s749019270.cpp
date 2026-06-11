#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define first F
#define second S
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t = 5;
	int arr[t];
	for(int i=0; i<t; i++){
		cin>>arr[i];
	}
	for(int i=0; i<t; i++){
		if(arr[i]==0)cout<<i+1<<endl;
	}
}

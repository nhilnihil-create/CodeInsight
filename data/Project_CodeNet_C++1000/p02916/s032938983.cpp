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
	int dish[n];
	map<int, int> B;
	map<int, int> C;
	for(int i=0; i<n; i++){
		cin>>dish[i];
	}
	for(int i=0; i<n; i++){
		int x; cin>>x;
		B[i+1]=x;
	}
	for(int i=0; i<n-1; i++){
		int x; cin>>x;
		C[i+1]=x;
	}
	int rta=0;
	for(int i=0; i<n-1; i++){
		rta+=B[dish[i]];
		if(dish[i+1]-dish[i] == 1){
			rta+=C[dish[i]];
		}
	}
	cout<<rta+B[dish[n-1]]<<endl;
}

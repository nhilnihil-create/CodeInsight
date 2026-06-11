#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int maxn = 1000000;
int eratoes[1000006];
bool visited[1000006];
bool pairwise = true;
int GCD(int a,int b){
	if(a<b) swap(a,b);
	while(b){
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}
void proccess(int a){
	vector<int>primes;
	while(a!=1){
		primes.push_back(eratoes[a]);
		a/=eratoes[a];
	}
	for(int i=0; i<primes.size(); i++){
		if(visited[primes[i]]) pairwise = false;
	}
	for(int i=0; i<primes.size(); i++){
		visited[primes[i]] = true;
	}
}
int main(){
	for(int i=2; i<=maxn; i++) eratoes[i] = i;
	for(int i=2; i*i<=maxn; i++){
		if(eratoes[i]==i){
			for(int j=i*i; j<=maxn; j+=i){
				eratoes[j] = i;
			}
		}
	}
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	for(int i=0; i<n; i++){
		proccess(arr[i]);
		if(!pairwise) break;
	}
	if(pairwise) cout<<"pairwise coprime";
	else{
		int gcd = arr[0];
		for(int i=1; i<n; i++) gcd = GCD(gcd,arr[i]);
		if(gcd==1) cout<<"setwise coprime";
		else cout<<"not coprime";
	}
}
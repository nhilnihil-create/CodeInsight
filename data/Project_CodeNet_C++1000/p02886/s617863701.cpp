#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll int>
#define vs vector<string>
#define v vector<int>
#define mi map<int,int>
#define mc map<char,int>
//ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,i,j,sum=0;
	cin>>n;
	v A(n);
	for(auto &x:A)cin>>x;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			sum+=(A[i]*A[j]);
			}
		}
		cout<<sum <<"\n";
}

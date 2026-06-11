#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll int>
#define vs vector<string>
#define v vector<int>
#define vd vector<double>
#define mi map<int,int>
#define mc map<char,int>
//ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int k,x;
	cin>>k >>x;
	v A;
	for(int i=k-1;i>=0;i--){
		A.push_back(x-i);
		}
		for(int i=k-1;i>0;i--){
			A.push_back(x+i);
			}
			sort(A.begin(),A.end());
			for(auto e:A)cout<<e <<" ";
			cout<<"\n";
			
}

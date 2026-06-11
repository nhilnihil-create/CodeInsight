#include <bits/stdc++.h>
#include <map>
#include <cmath>
typedef long long int ll;
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	int n;cin>>n;
	vector<pair<string,int> > vect;
	for(int i=0;i<n;i++){
		string s; int t;
		cin>>s>>t;
		vect.push_back(make_pair(s,t));
	}
	string x;cin>>x;
	int k=0;
	for(int i=0;i<n;i++){
		if(x.length()==vect[i].first.length()){
			bool flag = true;
			for(int j=0;j<x.length();j++){
				if(x[j]!=vect[i].first[j]){
					flag = false; break;
				}
			}
			if(flag==true){
				k = i+1; break;
			}
		}
	}
	ll sum=0;
	for(int i=k;i<n;i++){
		sum += vect[i].second;
	}
	cout<<sum<<endl;
}

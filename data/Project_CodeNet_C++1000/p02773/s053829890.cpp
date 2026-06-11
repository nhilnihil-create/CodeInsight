#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll int>
#define vs vector<string>
#define vi vector<int>
#define mi map<int,int>
#define mc map<char,int>

//ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(){
     ios_base::sync_with_stdio(false);cin.tie(NULL);
     int n,m=1;
     cin>>n;
     vs A(n);
     vs B;
     for(auto &x:A)cin>>x;
     map<string,int> map1;
     for(auto x:A)map1[x]++;
     //for(auto x:map1)cout<<x.first <<" " <<x.second <<"\n";
     for(auto x:map1){
		 m=max(m,x.second);
	 }
	 for(auto x:map1)
	 if(x.second==m){
		 B.push_back(x.first);}
		 else{continue;}
		 for(auto x:B)cout<<x <<"\n";
}

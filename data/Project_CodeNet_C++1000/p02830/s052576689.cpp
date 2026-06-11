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
	int n,i=0,j=0,q=0;
	cin>>n;
	string s,t,m="";
	cin>>s >>t;
	for(i=0;i<2*n;i++){
		if(i%2==0){
			m=m+s[q++];
			}
			else{m=m+t[j++];}
		}
		cout<<m <<"\n";
}


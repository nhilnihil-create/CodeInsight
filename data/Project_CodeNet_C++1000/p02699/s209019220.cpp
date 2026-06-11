//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll s,w;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>s>>w;
	if(w>=s)
	cout<<"unsafe";
	else
	cout<<"safe";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

vector <int> n;
 
int main(){

	ios::sync_with_stdio(false);
        cin.tie(NULL);
	string s;
	int n,ma=-1;
	map <string,int> a;
	vector <string> b,c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		a[s]++;
		if(a[s]==1){
			b.push_back(s);
		}
		ma=max(ma,a[s]);
	}
	for(int i=0;i<b.size();i++){
		if(a[b[i]]==ma){
			c.push_back(b[i]);
		}
	}
	sort(c.begin(),c.end());
	for(int i=0;i<c.size();i++){
		cout<<c[i]<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max(ll a, ll b){
	if(a>b)return a;
	else return b;
}

int main(){
    string s,t;
    cin>>s>>t;
    int sl=s.length(),tl=t.length();
    int maxx=0;
    for(int i=0;i<=sl-tl;i++){
    	int x=0;
		for(int j=i;j<tl+i;j++){
    		if(s[j]==t[j-i]){
    			x++;
			}
		}
		maxx=max(maxx,x);
	}
	cout<<tl-maxx<<endl;
}
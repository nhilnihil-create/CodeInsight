#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,int>pii;
//struct _IO { _IO() { ios::sync_with_stdio(0); cin.tie(0); } }_io;
const int maxn=1e5+10;
int a[maxn];
int main(){
	string s;
	cin>>s;
	int l,r;
	for(int i=0;i<s.size();){
		r=i;
		if(s[r]=='R'){
			while(s[r]=='R')  r++;
		}
		l=r;
		if(s[l]=='L'){
			while(s[l]=='L')  l++;
		}
		int c1=r-i,c2=l-r;
		if(~(c1+c2)&1){
			a[r-1]=(c1+c2)/2;
			a[r]=(c1+c2)/2;
		}
		else{
			int k=(c1+c2+1)/2;
			if(c1>c2){
				if(c1&1){
				 a[r-1]=k;
				 a[r]=k-1;
			  }
			  else{
				 a[r-1]=k-1;
				 a[r]=k;
			  }
			}
			else{
		   if(c2&1){
				 a[r-1]=k-1;
				 a[r]=k;
			  }
			  else{
				 a[r-1]=k;
				 a[r]=k-1;
			  }
			}
		}
		i=l;
	}
	for(int i=1;i<=s.size();i++) cout<<a[i-1]<<' ';
}
		
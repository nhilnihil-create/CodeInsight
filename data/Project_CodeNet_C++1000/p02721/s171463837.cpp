#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n,k,c,a[N],b[N];
string s;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>c>>s; 
	int cnt=0;
	for(int i=0;i<s.size()&&cnt<k;i++){
		if(s[i]=='o'){
			cnt++;
			a[i]=cnt;
			i+=c;
		}
	}
	cnt=0;
	for(int i=s.size()-1;i>=0&&cnt<k;i--){
		if(s[i]=='o'){
			cnt++;
			b[i]=cnt;
			i-=c;
		}
	}
	for(int i=0;i<s.size();i++){
		if(a[i]!=0&&b[i]!=0&&a[i]+b[i]==k+1) cout<<i+1<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define f first
#define  s second
#define pii pair<int,int>
#define pll pair<ll,l>
#define ull unsigned ll
#define mp make_pair
#define pb push_back

using namespace std;


int main(){
	
	int n;cin>>n;
	string s;cin>>s;
	int cnt1,cnt2;
	cnt1=cnt2=0;
	for(int i=0;i<n;i++){
		if(s[i]=='R')cnt1++;
		else cnt2++;
	}
	int cnt3=0,cnt4=0;
	for(int i=0;i<cnt1;i++){
		if(s[i]=='W')cnt3++;
	}
	for(int i=n-cnt2+1;i<n;i++){
		if(s[i]=='R')cnt4++;
	}
	cout<<max(cnt3,cnt4);
	return 0;
}

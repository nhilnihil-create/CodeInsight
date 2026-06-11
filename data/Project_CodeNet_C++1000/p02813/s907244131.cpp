#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int a[10],b[10],p[10];
int cnt1,cnt2;
bool f1,f2;
int n;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++) p[i]=i+1;
	do{
		if(f1&&f2) break;
		if(!f1) cnt1++;
		if(!f2) cnt2++;
		bool check=1;
		for(int i=0;i<n;i++){
			if(a[i]!=p[i]){
				check=0;
				break;
			}
		}
		if(check) f1=1;
		check=1;
		for(int i=0;i<n;i++){
			if(b[i]!=p[i]){
				check=0;
				break;
			}
		}
		if(check) f2=1;
	}while(next_permutation(p,p+n));
	cout<<abs(cnt1-cnt2);
	re 0;
}
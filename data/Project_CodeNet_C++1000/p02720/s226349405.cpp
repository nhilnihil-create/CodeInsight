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
queue<int> q;
int k;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>k;
	for(int i=1;i<=9;i++) q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		k--;
		if(!k){
			cout<<x;
			break;
		}
		int a=x%10;
		for(int i=-1;i<=1;i++){
			if(a+i<0||a+i>9) continue;
			q.push(x*10+a+i);
		}
	}
	re 0;
}
#include<bits/stdc++.h>

using namespace std;
#define llu unsigned long long
#define ll long long
#define p pair<int,int>
#define M 1000000007
//sieve can be used here!
bool isPrime(int n){
	if(n==1)return false;//1 is not prime
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}
bool myComp(p a,p b){
	if(a.first==b.first) return a.second<b.second;
	return a.first>b.first;
}
int row[]={-1,0,1,0};
int col[]={0,-1,0,1};
ll squareRoot(ll x){
	ll low=0;
	ll high=x;
	while(low<=high){
		ll mid= low+(high-low)/2;
		if((mid*mid)>x)high=mid-1;
		else if(mid*mid<x)low=mid+1;
		else return mid;
	}
	return low;
}
void dfs(char par,int r,int c,vector<vector<char>>& arr,vector<vector<bool>>& visited){
	int n=arr.size();
	int m=arr[0].size();
	visited[r][c]=true;
	arr[r][c]=par;
	for(int i=0;i<4;i++){
		int newRow=r+row[i];
		int newCol=c+col[i];
		if(newRow>=0&&newRow<n&&newCol>=0&&newCol<m&&!visited[newRow][newCol]&&arr[newRow][newCol]!='-'){
			if(par=='B') dfs('W',newRow,newCol,arr,visited);
			else dfs('B',newRow,newCol,arr,visited);
		}
	}
}
//DSu
int par[200003];
int sz[200003];
void initialiseDSU(){
	for(int i=0;i<200003;i++){
		par[i]=i;
		sz[i]=1;
	}
}
int find_root(int a){
	if(a==par[a])return a;
	par[a]=find_root(par[a]);
	return par[a];
}
int Union(int a,int b){//returns max size size after union
	int c=find_root(a);
	int d=find_root(b);
	if(c==d) return sz[c];
	if(sz[c]>sz[d]){
		par[d]=c;
		sz[c]+=sz[d];
		return sz[c];
	}
	else{
		par[c]=d;
		sz[d]+=sz[c];
		return sz[d];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	initialiseDSU();
	int n,m;
	cin>>n>>m;
	int ans=INT_MIN;
	while(m>0){
		int a,b;
		cin>>a>>b;
		ans=max(ans,Union(a,b));
		m--;
	}
	if(ans!=INT_MIN)cout<<ans;
	else cout<<1;
	return 0;
}


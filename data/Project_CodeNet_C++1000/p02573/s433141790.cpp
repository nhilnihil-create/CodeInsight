#include<bits/stdc++.h>
using namespace std;
int Parent(vector<int>&A, int i){
	while(A[i]!=i) i=A[i];
	return i;
}
void setParent(vector<int>&A,int i, int p){
	while(A[i]!=p){
		int a=A[i];
		A[i]=p;
		i=a;
	}
}
int solve(){
	int n,m,x,y,p1,p2;
	cin>>n>>m;
	vector<int>P(n+1);
	iota(P.begin(),P.end(),0);
	while(m--){
		cin>>x>>y;
		p1=Parent(P,x);
		p2=Parent(P,y);
		setParent(P,x,min(p1,p2));
		setParent(P,y,min(p1,p2));
	}
	vector<int>A(n+1);
	x=0;
	for(int i=1;i<=n;i++){
		p1=Parent(P,i);
		setParent(P,i,p1);
		A[p1]++;
		x=max(x,A[p1]);
	}
	return x;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<solve()<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
int N,n,add;
vector<pair<int,int> >ans;
void add_edge(int x,int y){
	ans.push_back(make_pair(x,y));
}
void print(){
	for(auto p:ans){
		cout<<p.first<<" "<<p.second<<endl;
	}
}
void solve0(){
	for(int i=1;i<n-1;i++)add_edge(i,i+1);
	add_edge(n-1,1+add);add_edge(1,n);
	for(int i=1;i<n-1;i++)add_edge(i+add,i+add+1);
	for(int i=0;i<N-1;i++){
		add_edge(n+i,n+i+1);
	}
	add_edge(n+N-1,add+n);
	for(int i=0;i<N-1;i++){
		add_edge(add+n+i,add+n+i+1);
	}
}
void solve1(){
	N--;solve0();N++;
	add_edge(N+n-1,n);
	add_edge(N+n-1+add,N-1);
}
void solve2(){
	for(int i=1;i<n-1;i++)add_edge(i,i+1);
	add_edge(n-1,1+add);
	for(int i=1;i<n-1;i++)add_edge(i+add,i+add+1);
	for(int i=n;i<n+N-1;i++)add_edge(i,i+1);
	for(int i=n+add;i<n+add+N-1;i++)add_edge(i,i+1);
	add_edge(1+add,n);
	add_edge(1+add,n+N-1+add); 
}
void solve3(){
	N--;solve2();N++;
	add_edge(N,add+add);
	add_edge(add,n);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>N;n=1;add=N;
	if(N==3){
		puts("Yes");
		puts("1 2");
		puts("2 3");
		puts("3 4");
		puts("4 5");
		puts("5 6");
		return 0;
	}
	while(n<N)n*=2;
	if(n==N){
		puts("No");
		return 0;
	}
	cout<<"Yes"<<endl;
	n/=2;N-=n-1;
	if(N%4==0){
		solve0();
	}else if(N%4==1){
		solve1();
	}else if(N%4==2){
		solve2();
	}else if(N%4==3){
		solve3();
	}
	print();
	return 0;
}
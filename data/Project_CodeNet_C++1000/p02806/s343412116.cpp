#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
	int N;
	cin>>N;
	vector<string>s(N);
	vector<int>t(N);
	rep(i,N){
		cin>>s.at(i)>>t.at(i);
	}
	string X;
	cin>>X;
	int time=0;
	rep(i,N){
		if(s.at(N-1-i)==X){
			cout<<time<<endl;
			return 0;
		}
		time+=t.at(N-1-i);
	}
return 0;}

/*compile
g++ code.cpp
./a.out
run*/
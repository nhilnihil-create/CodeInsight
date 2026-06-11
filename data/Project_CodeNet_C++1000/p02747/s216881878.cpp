#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
	string S;
	cin>>S;
	if(S.size()%2==0){
		rep(i,S.size()){
			if(i%2==0){
				if(S.at(i)=='h'){
					
				}else{
					cout<<"No"<<endl;
					return 0;
				}
			}else{
				if(S.at(i)=='i'){
					
				}else{
					cout<<"No"<<endl;
					return 0;
				}
			}
		}
	}else{
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
return 0;}

/*compile
g++ code.cpp
./a.out
run*/
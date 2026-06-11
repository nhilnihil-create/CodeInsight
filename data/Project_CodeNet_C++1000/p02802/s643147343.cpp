#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int wa[n+1]={0};
	int ac[n+1]={0};
	int c=0,w=0;
	while(m--){
		int q;
		string s;
		cin>>q>>s;
		if(s=="WA")wa[q]++;
		else if(s=="AC" && ac[q]==0){
			ac[q]++;
			c++;
			w+=wa[q];
		}
	}
	cout<<c<<" "<<w;
	return 0;
}
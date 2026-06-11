#include<iostream>
#include<string>
#define AC ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long 
using namespace std;

int n;
string s;
int cnt=1;

void backtrack(int m){
	if(m==n){
		cout<<s<<"\n";
		return;
	}
	for(int i=0;i<=cnt;i++){
		char c='a'+i;
		s+=c;
		int temp=cnt;
		cnt=max(cnt,s[m]-'a'+1);
		backtrack(m+1);
		cnt=temp;
		s=s.substr(0,s.length()-1);
	}
}

int main(){
	AC;
	cin>>n;
	s="a";
	backtrack(1);
}

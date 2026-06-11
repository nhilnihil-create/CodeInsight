#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
	string s; int n;
	cin>>n>>s;
	int tam=s.size();
	for(int i=0;i<tam;i++){
		if(s[i]+n<='Z'){
			s[i]=s[i]+n;
		}else {
			s[i]='A'+n-('Z'-s[i])-1;
		}
		
	}
	cout<<s;
	return 0;
}

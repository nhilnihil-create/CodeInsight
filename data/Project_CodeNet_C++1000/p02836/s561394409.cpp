#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
	string s;
	cin>>s;
	int tam=s.size();
	int r=0;
	
	for(int i=0;i<tam/2;i++){
		if(s[i]!=s[tam-i-1]){
			r++;
		
		}
		//cout<<s[i]<<" "<<s[tam-i-1]<<endl;
	}	
	cout<<r;
	return 0;
}

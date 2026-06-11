#include <bits/stdc++.h>
using namespace std;
 
int main() {
	char ca;
	cin>>ca;
	vector<char> a(26),b(26);
	for(int i=65; i<91; i++){
		a[i-65]=i;
	}
	for(int i=97; i<123; i++){
		b[i-97] = i;
	}
	
	for(int it=0; it<26; it++){
		if(a[it] == ca){
		 	cout<<"A";
		 	break;
		}
	}
	for(int it=0; it<26; it++){
		if(b[it] == ca){
		 	cout<<"a";
		 	break;
		}
	}
}
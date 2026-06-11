#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int count=0;
	cin>>s;
	for(int i=0;i<s.length()/2;i++){
	    if(s[i]==s[s.length()-i-1]){
	        count+=0;
	    }
	    else{
	        count+=1;
	    }
	}
	cout<<count;
	return 0;
}

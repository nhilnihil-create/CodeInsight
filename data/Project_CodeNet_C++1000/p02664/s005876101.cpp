#include <bits/stdc++.h>
using namespace std;
int i;
string t;

string easy(){
	for(i=1;i<t.size();i++){
    	if(t[i]=='?'){
    		t[i]='D';
		}
	}
	return t;
}

int main(){
    cin>>t;
    int s=0;
    for(i=0;i<t.size();i++){
    	if(t[i]=='P')break;
    	else easy();
	}
	for(i=1;i<t.size();i++){
	    if(t[i]=='D'&&t[i-1]=='?'){
	    	t[i-1]='P';
		}	 	
		if(t[i]=='?'&&t[i-1]=='P'){
			t[i]='D';
		}
	}	
	for(i=0;i<t.size();i++){
		if(t[i]=='?') t[i]='D';
	}
	cout<<t<<endl;
	return 0;
}

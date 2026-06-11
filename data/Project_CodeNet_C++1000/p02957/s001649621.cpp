#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	string ans="IMPOSSIBLE";
	int an=0;
	if(a<b){
    	for(int i=a;i<b;i++){
    		if(abs(a-i)==abs(b-i)){
    			an=i;
    			break;
    		}
    	}
	}else{
	    for(int i=b;i<a;i++){
    		if(abs(a-i)==abs(b-i)){
    			an=i;
    			break;
    		}
    	}
	}
	if(an!=0)cout<<an;
	else cout<<ans;
}
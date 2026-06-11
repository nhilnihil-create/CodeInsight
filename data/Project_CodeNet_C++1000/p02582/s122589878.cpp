#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[4];
	int max = 0,c = 0;
	cin >> s;
	
	for(int i = 0; i < 3; i++){
	    if(s[i]=='R'){
	        c++;   
	    }else{
	        c = 0;
	    }
	    if(max < c){
	        max=c;
	    }
	}
	cout<<max<<endl;
}
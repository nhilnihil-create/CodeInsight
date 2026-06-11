#include <bits/stdc++.h>
using namespace std;

int main() {
	string a;
	cin>>a;
	int max=0,flag=0,temp=0;
	for(int i=0;i<a.size();i++){
	    if(a[i]=='R'){
	        if(flag==0){
	            flag=1;
	            temp=1;
	        }
	        
	        else
	        temp++;
	    }
	    else{
	        if(max<temp)
	        max=temp;
	        flag=0;
	        temp=0;
	    }
	}
	if(max<temp)
	max=temp;
	cout<<max;
	return 0;
}

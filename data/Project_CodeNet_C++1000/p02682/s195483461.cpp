#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	int sum = 0;
	
	for(;k > 0; k--){
	    if(a > 0){
	        a--;
	        sum++;
	    }else if(b > 0){
	        b--;
	    }else if(c > 0){
	        c--;
	        sum--;
	    }
	}
	cout<<sum<<endl;
}

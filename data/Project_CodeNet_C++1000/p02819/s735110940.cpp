#include<bits/stdc++.h>
using namespace std;
 
int main(){
	   
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	while(1){
	   bool flag = true;
	    for(int i=2; i<n; i++){
	        if(n%i==0){
	            flag = false;
	            break;
	        }
	    }
	    if(flag) break;
	    n++;
	}
	cout<< n <<endl;
	 
return 0;
}
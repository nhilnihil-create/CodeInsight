#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int s[n][2];
    int temp=0;
    
    for(int i=0;i<n;i++){
    	cin>>s[i][0]>>s[i][1];
    	
	}
	
	for(int i=0;i<n;i++){
		if(s[i][0]==s[i][1]){
    		temp++;
		}else{
			temp=0;
		}
		if(temp==3){
			break;
		}
	}
    if(temp==3){
    	cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
    
    return 0;
}

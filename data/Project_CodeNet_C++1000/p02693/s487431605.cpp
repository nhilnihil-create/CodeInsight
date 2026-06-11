#include<bits/stdc++.h>

using namespace std;

int main(){
    int k;
    cin>>k;
    int a,b;
    cin>>a>>b;
    for(int i=1;;i++){
    	if(i*k > b) {
    		cout<<"NG"<<endl;
    		break;
		}
		if(i*k>=a && i*k<=b){
			cout<<"OK"<<endl;
			break;
		}
	}
	return 0;
} 
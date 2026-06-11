#include<bits/stdc++.h>
using namespace std;
int r[]={1799,1599,1399,1199,999,799,599,399};
int main(){
	int x;
	cin>>x;
	for(int i=0;i<8;i++){
	    if(x>r[i]){
	        cout<<i+1<<endl;
	        return 0;
	    }
	}
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
  	cin >>s;
  	int max=0;
  	int count=0;
  	for(int i=0;i<s.size();i++){
    	if(s[i]=='R'){
          count++;
        }
      	else{
        	count=0;
        }
      	if(max<count){
          	max=count;
        }
    }
	cout << max << endl;
}
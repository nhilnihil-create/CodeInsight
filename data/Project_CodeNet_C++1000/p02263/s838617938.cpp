#include<bits/stdc++.h>
using namespace std;
int osikomi(int s[]){
	for(int i = 0;i<100;i++){
		if(s[i] == 0){
			s[i] = s[i+1];
			s[i+1] = 0;
		}
	}
}
int main(){
    int l, i=0;
    int s[200] = {};
    string x;

    while(cin>>x){
    	for(int i = 0;i<50;i++){
    		osikomi(s);
    	}
    //	cout<<"i"<<i<<endl;
    	if(x == "+"){
   	for(int i = 100;i>0;i--){
   		if(s[i] != 0){
   			s[i-1] += s[i];
   			s[i] = 0;
   			break;
   		}
   	}i--;
    //	cout<<"+"<<endl;
    	}
    	else if(x == "/"){
   		for(int i = 100;i>0;i--){
   			if(s[i] != 0){
   			s[i-1] /= s[i];
   			s[i] = 0;
   			break;
   			}
   		}
   		i--;
 	   	
  
    	//	cout<<"/"<<endl;
    	}
    	else if(x == "-"){

  		for(int i = 100;i>0;i--){
   		if(s[i] != 0){
   			s[i-1] -= s[i];
   			s[i] = 0;
   			break;
   		}
   	}i--;
    //		 cout<<"-"<<endl;

    	}
    	else if(x == "*"){
 		 for(int i = 100;i>0;i--){
   			if(s[i] != 0){
   				s[i-1] *= s[i];
   				s[i] = 0;
   				break;
   			}
   		}i--;
    	//	cout<<"*"<<endl;
    	}
    	else{
    		s[i] = stoi(x);
   		}
    	osikomi(s);
    	i++;
    //	for(int i = 0;i<10;i++){
   // 		cout<<s[i]<<" ";
   // 	}
   // 	cout<<endl;
    }
    cout<<s[0]<<endl;
}

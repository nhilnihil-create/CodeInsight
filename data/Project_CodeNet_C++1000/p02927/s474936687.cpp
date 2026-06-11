#include<iostream> 
#include<bits/stdc++.h> 
using namespace std;
int mod(int a,int b){ 
	return (a%b+b)%b; 
}
int f(int m,int D){ 
	int last=D/10; 
	int ct=0; 
	for(int j=2;j<last;j++){ 
	       for(int i=2;i<10;i++){ 
		       if((i*j)==m){ 
			       ct++;
		       } 
	       } 
	} 
	if(last>=2){ 
	       for(int j=2;j<=(D%10);j++){ 
	       		if((last*j)==m){ 
		 		ct++; 
			}		
	       } 
	}
	       			       
	return ct; 
}	

int main(){ 
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	int M,D; 
	cin>>M>>D; 
	int ct=0; 
	for(int i=1;i<=M;i++){ 
		ct+=f(i,D); 
	} 
	cout<<ct<<endl; 


	
	return 0;
} 


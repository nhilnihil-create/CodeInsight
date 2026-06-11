#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
using namespace std;
int main(){
  	double D,T,S;
  	cin>>D>>T>>S;
  	if(((double)D/(double)S)<=T){
    	cout<<"Yes";
    }
  	else{
    	cout<<"No";
    }
  	return 0;
}
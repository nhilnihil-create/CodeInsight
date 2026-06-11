#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
int main(void){
    // Your code here!
    long double a,b,c=0,d,e,f,g=0;
    int A[1000];
    while(1){
    
    cin>>b;
    if(b==0){
    	break;
    }
    for(int i=0;i<b;i++){
    	cin>>A[i];
    	c+=A[i];
    }
    c=c/b;
    for(int i=0;i<b;i++){
    	g+=pow((A[i]-c),2)/b;
    }
    g=sqrt(g);
    //cout<<printf("%.10lf\n", sqrt(e))<<endl;
    //e=sqrt(e);
    // cout << f << endl;
    std::cout << setprecision(16) << g <<endl;
    c=0;
    g=0;
    A[1000]=0;
	}
    return 0;
}


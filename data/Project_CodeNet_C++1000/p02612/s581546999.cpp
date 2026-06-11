#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n;
    cin>>n;
    if(n%1000==0){
      cout<<0<<endl;
    }else
    {
       int ans=1000-n%1000;
       cout<<ans<<endl;
    }
    
   
	
	return 0;
}
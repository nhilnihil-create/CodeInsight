#include<bits/stdc++.h>

using namespace std;


int main(){
	#ifndef ONLINE_JUDGE  
    freopen("i.txt", "r", stdin); 
    freopen("o.txt", "w", stdout); 
    #endif
    string s="ACL";
    int n;
    cin>>n;
    string ans="";
    for(int i=0;i<n;i++){
    	ans+=s;
    }
    cout<<ans<<endl;

}
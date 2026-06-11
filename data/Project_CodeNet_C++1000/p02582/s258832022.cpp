#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
int mod=int(1e9)+7;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    string s;
    cin>>s;
    if(s=="RRR"){
    	cout<<3<<endl;
    }
    if(s=="RRS"||s=="SRR"){
    	cout<<2<<endl;
    }
    if(s=="RSR"||s=="RSS"||s=="SRS"||s=="SSR"){
    	cout<<1<<endl;
    }
    if(s=="SSS"){
    	cout<<0<<endl;
    }
}
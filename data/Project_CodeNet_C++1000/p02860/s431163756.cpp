#include <bits/stdc++.h>

using namespace std;



int main(){
    
    int n;
    string s;
    cin>>n>>s;
    if(n&1) cout<<"No";
    else{
    	string a = s.substr(0,n/2);
    	string b = s.substr(n/2,n);
    	if(a!=b) cout<<"No";
    	else cout<<"Yes";
    }

    return 0;
}

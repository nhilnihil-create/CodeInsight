#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        string s,t,u;
        cin>>s>>t;
        int a,b;
        cin>>a>>b;
        cin>>u;
        if(u==s)
        cout<<(a-1)<<" "<<b;
        else if(u==t)
        cout<<a<<" "<<b-1;
        // your code goes here
	return 0;
}

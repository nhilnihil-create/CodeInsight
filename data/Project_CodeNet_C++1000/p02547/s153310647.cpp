#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int n; cin>>n;
    int c = 0; int flag = 0;
    while(n--){
        int a, b;
        cin>>a>>b;
        if(a==b) c++;
        else c=0;
        
        if(c==3){
            flag = 1;
            break;
        }
    }
    
    if(flag==1) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}
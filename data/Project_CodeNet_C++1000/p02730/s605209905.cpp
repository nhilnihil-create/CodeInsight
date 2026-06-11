#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e18
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    string s;
    cin>>s;
    int n=s.length();
    string ss[(n+1)/2];
    for(int i=0; i<(n-1)/2; i++) ss[i] = s[i];
    int flag=1;
    for(int i=0; i<(n-1)/2; i++){
        if(s[i]!=s[n-i-1]) flag=0;
    }
    n = (n-1)/2;
    if(n%2==1){
        for(int i=0; i<(n-1)/2; i++){
            if(ss[i]!=ss[n-i-1]) flag=0;
        }
    }
    else{
        for(int i=0; i<n/2; i++){
            if(ss[i]!=ss[n-i-1]) flag=0;
        }
    }
    
    if(flag==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl; 



    return 0;
}
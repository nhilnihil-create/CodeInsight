#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size()/2;
    int m=n/2;
    int count=0;
    for(int i=0;i<m;i++){
        if(s.at(i)!=s.at(n-i-1)) count++;
        else if(s.at(n+1+i)!=s.at(s.size()-i-1)) count++;
    }
    for(int i=0;i<m;i++){
        if(s.at(i)!=s.at(s.size()-i-1)) count++;
    }
    if(n%2!=0){
        if(s.at(m)!=s.at(n+m+1)) count++;
    }
    if(count>0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    
}
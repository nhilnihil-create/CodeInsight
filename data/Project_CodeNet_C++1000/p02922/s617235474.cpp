#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int count=0;
    int sum=0;
    if(b==1) cout <<"0"<<endl;
    else{
    for(int i=0;i<20;i++){
        sum+=a-1;
        count++;
        if(sum>=b-1) break;
    }
    cout<<count<<endl;
    }   
}
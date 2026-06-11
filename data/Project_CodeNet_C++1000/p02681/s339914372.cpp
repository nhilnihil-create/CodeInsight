#include<bits/stdc++.h>
using namespace std;

int x=0;
string a,b;
char i;



int main(){
    cin>>a>>b;
    for(i=0;i<=a.length()-1;i++){
        if(a[i]!=b[i]){
            x=x+1;
        }
    }
    if(x>=1){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }
}
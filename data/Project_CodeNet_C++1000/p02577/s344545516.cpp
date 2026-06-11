#include<bits/stdc++.h>
using namespace std;

int main(){
    char x = ' ';
    int sum=0;
    while(cin>>x){
            sum = (sum + x-'0')%9;
    }
    if(sum==0){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}

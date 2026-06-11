#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int cnt=0;
    do{
        cnt++;
        n=n/k;
    }while(n!=0);
    
    cout<<cnt<<endl;
    return 0;
}
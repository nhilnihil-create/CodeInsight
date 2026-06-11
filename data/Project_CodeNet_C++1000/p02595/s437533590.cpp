#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,st;
    cin>>n>>st;
    int cnt=0;
    for(int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        if(sqrt(a*a+b*b)<=st) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
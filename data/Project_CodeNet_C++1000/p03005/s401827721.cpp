#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    if(k==1)
        cout<<0<<endl;
    else if(k==2)
        cout<<n-2<<endl;
    else{
        n = n-1;
        n = n-(k-2);
        cout<<n-1<<endl;
    }
    return 0;
}

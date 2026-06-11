#include<bits/stdc++.h>
using namespace std;
int main(){

    int m,n,req;
    cin>>m>>n>>req;

    cout<<ceil(req*1.0/max(m,n)*1.0);

    return 0;   
}
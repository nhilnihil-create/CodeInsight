#include<bits/stdc++.h>
using namespace std;

int main(){
    int p,q,r,v[3];
    cin>>p>>q>>r;
    v[0]=p;
    v[1]=q;
    v[2]=r;
    sort(v,v+3);
    cout<<v[0]+v[1]<<endl;
       
}
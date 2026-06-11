#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,k;cin>>a>>b>>c>>k;
    int zbr=0;
    zbr+=min(a,k);
    k-=min(a,k);
    k-=min(b,k);
    zbr-=min(c,k);
    cout <<zbr<<endl;
}

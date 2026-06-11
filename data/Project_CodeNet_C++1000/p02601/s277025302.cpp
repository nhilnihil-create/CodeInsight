#include<bits/stdc++.h>
using namespace std;

int main(){
    float a,b,c;
    int k;
    cin>>a>>b>>c>>k;
    int k1=0,k2=0;
    if(b<=a){
        k1 = floor(log2(a/b)) + 1;
        b = b*pow(2,k1);
    }
    if(c<=b){
        k2 = floor(log2(b/c)) + 1;
    }
    if(k>=k1+k2) cout<<"Yes\n";
    else cout<<"No\n";
}
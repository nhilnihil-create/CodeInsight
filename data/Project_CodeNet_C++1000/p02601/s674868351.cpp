#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    int k;
    cin >>a>>b>>c>>k;

    while(k--){
        if(2*a<b)   a=2*a;
        else if(2*b<c)  b = 2*b;
        else    c=2*c; 
    }

    if(a<b && b<c)  cout <<"Yes"<<endl;
    else    cout <<"No"<<endl;

    return 0;
}
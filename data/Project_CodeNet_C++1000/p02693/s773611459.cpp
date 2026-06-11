#include<bits/stdc++.h>
using namespace std;
int main(){
        int k; cin>>k;
        int a,b; cin>>a>>b;
        int v1=a/k,v2=b/k;
        if(v1==v2&&(v1*k)<a) cout<<"NG"<<endl;
        else { cout<<"OK"<<endl;}
}

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    long long a,b,k;
    cin>>a>>b>>k;
    
    if(a>=k){
        cout<<a-k<<" "<<b<<endl;
    }else if(a+b>=k){
        cout<<0<<" "<<a+b-k<<endl;
    }else{
        cout<<0<<" "<<0<<endl;
    }
    return 0;
}
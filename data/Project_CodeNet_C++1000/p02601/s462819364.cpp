#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int a,b,c,k;
int main(void){
    cin>>a>>b>>c>>k;
    while(k--){
        if(a>=b){
            b=b*2;
        }else if(b>=c){
            c=c*2;
        }
        //cout<<a<<" "<<b<<" "<<c<<endl;
    }
    if(a<b&&b<c){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}


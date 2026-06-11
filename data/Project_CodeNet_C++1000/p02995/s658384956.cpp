#include<iostream>
using namespace std;
using ll=long long;

int main(){
    ll A,B,C,D;
    cin>>A>>B>>C>>D;
    ll sum=B-A+1;
    ll C_cnt=B/C-((A-1)/C);
    ll D_cnt=B/D-((A-1)/D);
    ll x=C*D;
    if(C<D){
        ll temp=C;
        C=D;
        D=temp;
    }
    ll r=C%D;
    while(r!=0){
        C=D;
        D=r;
        r=C%D;
    }
    x=x/D;
    ll x_cnt=B/x-((A-1)/x);
    cout<<sum-(C_cnt+D_cnt)+x_cnt<<endl;
    return 0;
}
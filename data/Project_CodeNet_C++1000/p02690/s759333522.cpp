#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll x;
    cin>>x;
    for(ll i=0;;i++){
        float num = pow(x+pow(i,5),0.2);
        //ll res = pow(x-pow(i,5),0.2)/1;
        if(floor(num) == num){
            cout<<num<<" "<<i;
            break;
        }
        float num2 = pow(x+pow(-i,5),0.2);
        //ll res2 = pow(x-pow(-i,5),(1/5))/1;
        if(floor(num2) == num2){
            cout<<num2<<" "<<-i;
            break;
        }
    }
    return 0;

}

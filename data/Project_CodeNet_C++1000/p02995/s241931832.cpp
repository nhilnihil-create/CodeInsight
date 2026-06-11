#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

ll lcm(ll a,ll b){
    if(b==0){
        return a;
    }else{
        return lcm(b,a%b);
    }
}
int main(){
    ll A,B,C,D;
    cin>>A>>B>>C>>D;
    A--;
    ll E=(A-A/C)+(A-A/D)-(A-A/(C/lcm(C,D)*D));
    ll F=(B-B/C)+(B-B/D)-(B-B/(C/lcm(C,D)*D));
    
    cout<<F-E;
}
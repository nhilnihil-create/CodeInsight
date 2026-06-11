#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;


int main(){

    ll a;
    lld b;
    cin>>a>>b;
    b=round(b*100);
    ll mul=a*b;
    cout<<mul/100<<endl;

}

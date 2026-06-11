#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define MOD 1000000007
#define PI 3.1415


int main(){
    ll x;
    cin>>x;

    ll v =100;
    ll co=0;
    while(x>v){
        v = v+(v/100);
        co++;
    }
    cout<<co<<endl;

}


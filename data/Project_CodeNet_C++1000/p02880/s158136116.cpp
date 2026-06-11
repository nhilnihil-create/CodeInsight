#include<bits/stdc++.h>
#define ll              long long int
#define nl              '\n'
using namespace std;

int main(void){

    ll a,b;
        cin>>a;

    for(int i=1; i<=9; i++){
        for(int j=i; j<=9; j++){
            if(i*j==a){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
}

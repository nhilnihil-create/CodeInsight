#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;



int main(){
    int a, b; cin>>a >>b;
    rep(i,10200){
        if(floor(i * 0.08) == a && floor(i * 0.10) == b){
            cout<< i <<endl;
            return 0;
        }
    }
    cout<< -1 <<endl;
}

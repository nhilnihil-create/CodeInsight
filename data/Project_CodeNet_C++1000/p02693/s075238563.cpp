#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int MOD = 1e9+7;
const int N = 5*1e5;



int main(){
    AC
    int x, a, b;
    cin>>x>>a>>b;
    int ans = x;
    while(ans<=b){
        if(ans>=a && ans<=b){
            cout<<"OK"<<endl;
            return 0;
        }
        ans+=x;
    }
    cout<<"NG"<<endl;
}
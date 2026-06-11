#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

int main(){
    AC
    int n;
    cin>>n;
    ll res;
    cin>>res;
    if(res==0){
        cout<<0<<endl;
        return 0;
    }
    bool flag = false;
    for(int i=1; i<n; i++){
        ll x;
        cin>>x;
        if(x>0 && res>9223372036854775807/x){
            // overflow
            flag = true;
        }
        res*=x;
        if(x==0){
            cout<<0<<endl;
            return 0;
        }
        else if(res>1000000000000000000){
            flag = true;
        }
    }
    if(flag)
        cout<<-1<<endl;
    else
        cout<<res<<endl;
}
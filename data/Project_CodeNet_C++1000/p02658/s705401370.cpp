#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main(){
    int n;  cin >> n;
    
    ll a = 1;
    vector<ll> b(n);
    for(int i=0;i<n;i++) {
        cin >> b[i];
        
    }

    for(int i=0;i<n;i++){
        if(b[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }

    for(int i=0;i<n;i++){
        if(b[i]<=1000000000000000000/a){
             a *= b[i];
             }
        else {
            cout << -1 << endl;
            return 0;
            }
        }
         cout << a << endl;
    }
       

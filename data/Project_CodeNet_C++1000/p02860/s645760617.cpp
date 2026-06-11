#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vll vector<pair<ll, ll>
using namespace std;


int main(){
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    ll n, ans = 0;
    cin >> n;
    string x;
    cin >> x;
    
    if(n%2 == 1){
        cout << "No" << endl;
    }
    else{
        bool f = true;
        ll temp = n/2;
        for(ll i=0; i<temp; i++){
            if(x[i] == x[i+temp]){
                continue;
            }
            else{
                f = false;
                break;
            }
        }
        
        if(f){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
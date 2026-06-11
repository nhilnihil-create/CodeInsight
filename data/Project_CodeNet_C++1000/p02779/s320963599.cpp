
/**
 *    author        : Sudipta Banik Trisha 
 *    created       : September 10, 2020 4:57 PM
 *    Problem Name  : C - Distinct or Not
 *    Problem Limit : 2000 ms , 1024 MB
 *    Problem Url   : https://atcoder.jp/contests/abc154/tasks/abc154_c
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
#define ll long long int 
#define sz 1000000000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin >> v[i];   
    }
    sort(v.begin(),v.end());
    for(ll i=0; i<n; i++) {
        if(v[i] != v[i+1]){
            continue;
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0 ;
}

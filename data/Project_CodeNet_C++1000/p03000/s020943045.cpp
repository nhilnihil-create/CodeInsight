#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<string>

using namespace std;
#define ll long long

int main(){
    ll N, X;
    ll sum = 0;
    ll ans = 1;
    cin >> N >> X;
    vector<ll> L(N+2,0);
    for(int i = 0; i < N; i++){
        cin >> L[i];
        sum += L[i];
        if(sum > X){
            cout << ans << endl;
            return 0;
        }else{
            ans++;
        }
    }
    cout << ans << endl; 
    return 0;
}
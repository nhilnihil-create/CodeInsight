#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <functional>

#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

int main(){
    ll N,K,Q;
    cin >> N >> K >> Q;
    vector<ll> v(N,0);
    for(int i=0; i < Q ;i++){
        int j;
        cin >> j;
        v[j-1]++;
    }
    for(int i=0;i<N;i++){
        if(v[i] - Q + K > 0)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll N, K, Q, buf;
    cin >> N >> K >> Q;
    unordered_map<int,int> UM;
    for(int i = 1; i <= Q; ++i){
        cin >> buf;
        ++UM[buf];
    }
    for(int i = 1; i <= N; ++i){
        if(K - (Q-UM[i]) > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

using ll = long long;
using namespace std;

ll mod = 1e9+7;

#define int ll

std::vector<int> PrimeFactoring(int N){
    std::vector<int> ans;
    bool f = true;
    while(N != 1 && f){
        for(int a = 2;a <= N && f;a++){
            if(N % a == 0){
                N /= a;
                ans.push_back(a);
                break;
            }
            if(a > sqrt(N)){
                f = false;
                break;
            }
        }
    }
    if(N != 1)ans.push_back(N);
    return ans;
}

signed main() {
    ll A, B;cin >> A >> B;
    vector<int> X = PrimeFactoring(A);
    vector<int> Y = PrimeFactoring(B);
    //cout<<"AA"<<endl;
    set<int> Q, W;
    for(int i : X){
        Q.insert(i);
    }
    for(int j : Y){
        W.insert(j);
    }
    ll ans = 0;
    for(auto a : Q){
        if(W.find(a) != W.end())ans++;
    }
    cout<<ans + 1<<endl;
}

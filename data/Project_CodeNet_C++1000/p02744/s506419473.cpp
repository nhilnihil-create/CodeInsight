#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

using ll = long long;

using namespace std;

vector<string> ans;
int n;

void solve(int i, string s){
    if(i == n){
        ans.push_back(s);
        return;
    }
    char c = *max_element(s.begin(), s.end());
    if(s == ""){
        solve(i + 1, s + 'a');
    }else
    if(c == 'z'){
        for(int j = 0;j < 26;j++){
            char w = 'a' + j;
            solve(i + 1, s + w);
        }
    }else{
        for(int j = 0;j <= c - 'a' + 1;j++){
            char w = 'a' + j;
            //cout<<w<<endl;
            solve(i + 1, s + w);
        }
    }
}

signed main() {
    cin >> n;
    solve(0, "");
    for(auto a : ans){
        cout<<a<<endl;
    }
}



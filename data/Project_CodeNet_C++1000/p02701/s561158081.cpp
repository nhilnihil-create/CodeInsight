#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    ll n;
    cin>>n;
    vector<string> s(n);
    int count=1;
    rep(i,n){
        cin>>s[i];
    }
    sort(s.begin(),s.end());
    s.push_back(s.back());
    rep(i,n){
        if(s[i] != s[i+1]){
            count++;
        }
    }
    cout<<count<<endl;
}
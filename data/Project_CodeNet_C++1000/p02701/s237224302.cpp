#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll res=0;
    set<string> S;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        S.insert(s);
    }
    cout<<(int)S.size();
    return 0;
}
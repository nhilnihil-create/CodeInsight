#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; string S; cin >> N >> S;
    vector<int> a(N);
    int one=0,ans=0;
    for (int i=0;i<N;++i){
        a[i]=S[i]-'1';
        one|=(a[i]==1);
    }
    for (int i=0;i<N;++i) if (((N-1)&i)==i) ans^=(one?a[i]%2:a[i]/2);
    cout << ans*(one?1:2) << '\n';
}
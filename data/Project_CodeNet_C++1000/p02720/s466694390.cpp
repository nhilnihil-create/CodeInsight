#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int k;
    cin>>k;

    queue<array<ll,2>> q;

    for(int i = 1; i <= 9; i++) q.push({i,i});

    ll cnt = 0;
    ll res = 0;
    while(cnt<k){
        auto t = q.front();
        res = t[0];
        q.pop();

        ll nt = t[0]*10;
        if(t[1]!=0)q.push({nt+(t[1]-1),t[1]-1});
        q.push({nt+(t[1]),t[1]});
        if(t[1]!=9)q.push({nt+(t[1]+1),t[1]+1});
        cnt++;
    }
    cout<<res;

}

#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cnt(n,0);
    int now = 1;
    ll fir = 0;
    ll sec = 0;
    while(true){
        int next = a[now-1];
        cnt[now-1]++;
        if(cnt[now-1] == 1)fir++;
        else if(cnt[now-1] == 2)sec++;
        else if(cnt[now-1] == 3)break;
        now = next;
    }
    if(k <= fir){
        now = 1;
        rep(i,k){
            int next = a[now-1];
            now = next;
        }
    }
    else{
        k -= fir;
        k %= sec;
        rep(i,k){
            int next = a[now-1];
            now = next;
        }
    }
    cout << now << endl;
}
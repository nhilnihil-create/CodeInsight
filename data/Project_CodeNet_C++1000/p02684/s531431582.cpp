#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll N, K;
    cin >> N >> K;

    ll A[N];
    rep(i, N) cin >> A[i];

    int k=0;
    int st;
    int root[N]={0};
    int wi=0;
    int now=0;
    while(k<K){
        root[now]=1;
        k++;
        if(root[A[now]-1]==1){
            st=A[now]-1;
            now=st;
            while(true){
                wi++;
                now=A[now]-1;
                if(now==st) break;
            }
            break;
        }
        now=A[now]-1;
        root[now]=1;
    }

    int ans;
    if(k==K) ans=now+1;
    else{
        int num=(K-k)%wi;
        rep(i, num) now=A[now]-1;
        ans=now+1;
    }

    cout << ans << endl;
    return 0;
}
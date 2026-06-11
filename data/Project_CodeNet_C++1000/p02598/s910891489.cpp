#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, K;
    cin>>N>>K;
    int A[N];
    int max=0;
    rep(i, N){
        cin>>A[i];
        max=fmax(max, A[i]);
    }
    //binary search
    int now=max;
    int up=N;
    int low=0;
    int ans=0;

    while(true){
        int cut_num=0;
        rep(i, N) if(A[i]>=now) cut_num+=((A[i]+now-1)/now)-1;
        if(cut_num>K){
            low=now;
            now=(up+low)/2;
        }else{
            ans=now;
            up=now;
            now=(up+low)/2;
        }

        if(abs(up-low)==1) break;
    }

    cout<<ans<<endl;
    return 0;
}
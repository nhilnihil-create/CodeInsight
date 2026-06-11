#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N; cin>>N;
    vector<ll> bl(N+1,0),A(N+1,0);
    
    rep(i,N){
        int x; cin>>x;
        bl[x]++;
        A[i+1]=x;
    }
    
    //ボールを除く前
    ll sum=0;
    for(int i=1; i<=N; i++){
        if(bl[i]>=2){
            sum += (bl[i]*(bl[i]-1))/2;
        }
    }
    
    //ｋ番目のボールを除いたとき
    for(int k=1; k<=N; k++){
        ll ans=sum;
        if(bl[A[k]]>=2){
            ans -= (bl[A[k]]-1);
        }
        cout << ans << endl;
    }
}

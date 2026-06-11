#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll N,S;
ll K;
ll ans=0;
ll A[10000];
ll B [200001];




int main(){
    cin >> N>>S;
    
    if(S == 2 || S==5){
        for(int i=0;i<N;i++){
            char a;
            cin >> a;
            int d = a-'0';
            if(d%S==0){
                ans += i+1;
            }
        }
    }else{
        for(int i=0;i<N;i++){
            char a;
            cin >> a;
            int d =a-'0';
            B[i] = d;
        }
        ll b = 1;
        ll c = 0;
        for(int i=0;i<N;i++){
            c = (c + b*B[N-i-1])%S;
            A[c]+=1;;
            b *= 10;
            b %= S;
        }
        A[0] += 1;
        for(int i= 0;i<S;i++){
            ans += A[i]*(A[i]-1)/2;
        }
    }
    
    cout << ans << endl;
    
}
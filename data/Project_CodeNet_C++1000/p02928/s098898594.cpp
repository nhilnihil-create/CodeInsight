#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define ll long long
int main(){
    ll N,K,i,j;
    cin >> N >> K;
    ll A[N];
    for(i=0;i<N;i++){
        cin >> A[i];
    }
    ll part=0;
    for(i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
            if(A[i]>A[j])part++;
        }
    }
    ll ans=part*K%1000000007;
    sort(A,A+N);
    ll same=1;
    ll num=(K*(K-1)/2)%1000000007;
    for(i=N-1;i>0;i--){;
        if(A[i]==A[i-1])same++;else {
            ans=(ans+same*i*num)%1000000007; 
            same=1;
        }       
    }
    cout << ans;
    return 0;
}
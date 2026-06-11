#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    vector<ll> A(N+1);
    for(int i=0; i<=N; i++){
        cin >> A[i];
    }

    vector<ll> ul(N+1,MOD*MOD);
    vector<ll> dl(N+1,MOD*MOD);

    ul[0]=1;
    for(int i=1; i<=N; i++){
        ul[i]=min(MOD*MOD,2LL*(ul[i-1]-A[i-1]));
    }

    dl[N]=A[N];
    for(int i=N-1; i>=0; i--){
        dl[i]=dl[i+1]+A[i];
    }

    ll ans=0;
    ll prev=0;
    for(int i=N; i>=0; i--){
        ll cnt=min(ul[i],dl[i]);
        if(cnt<prev/2+prev%2+A[i]){
            cout << -1 << endl;
            return 0;
        }else{
            ans+=cnt;
            prev=cnt;
        }
    }
    cout << ans << endl;
}
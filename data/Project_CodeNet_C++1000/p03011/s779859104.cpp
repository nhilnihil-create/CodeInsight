#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define INF 100000000
int main(){
    ll P,Q,R;
    cin>>P>>Q>>R;
    ll x=max(max(P,Q),R);
    cout<<(P+Q+R)-x<<endl;
}
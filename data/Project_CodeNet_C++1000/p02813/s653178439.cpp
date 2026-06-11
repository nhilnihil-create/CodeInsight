#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353a
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N;
    cin>>N;
    vector<int>P(N);
    vector<int>Q(N);
    for(int i=0;i<N;i++)cin>>P.at(i);
    for(int i=0;i<N;i++)cin>>Q.at(i);
    if(P>Q)swap(P,Q);
    int ans=0;
    do{
        if(P==Q)break;
        ans++;
    }while(next_permutation(P.begin(),P.end()));

    cout<<ans<<endl;
}

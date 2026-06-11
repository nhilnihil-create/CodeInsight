#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>

void test_case()
{
    int N=100010;
    vector<int> primes={2};
    bool vis[N]={};

    for(int i=3; i*i<=N; i+=2) {
        if(!vis[i]) {
            for(int j=i*i; j<=N; j+=2*i) {
                vis[j]=1;
            }
        }
    }

    for(int i=3; i<=N; i+=2) {
        if(!vis[i])
            primes.pb(i);
    }
    int x;
    cin>>x;
    cout<<*lower_bound(primes.begin(), primes.end(), x);


}


int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}

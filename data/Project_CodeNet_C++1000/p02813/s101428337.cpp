#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod=1e9+7;
// Not for Rating """"""""""I'm in Love with Experience :)""""""""""""""""""
void solve()
{
    ll N;cin>>N;
    std::vector<ll> A,B,C;
    int x;
    for(ll i=0;i<N;++i)
    {
        cin>>x;A.push_back(x);
    }
    for(ll i=0;i<N;++i)
    {
        cin>>x;B.push_back(x);
    }
    C=B;
    sort(C.begin(),C.end());
    ll a=0,b=0,c=0;
    do{
        c++;
        if(C==A)a=c;
        if(C==B)b=c;
    }while(next_permutation(C.begin(),C.end()));
    cout<< abs(b-a);
}
int main(void)
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T=1;while(T--){solve();}return 0;
}/*Solved By:- RITIK AGARWAL*/
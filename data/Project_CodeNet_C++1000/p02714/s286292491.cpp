#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    ll r=0;ll g=0;ll b=0;
    for (ll i = 0; i < N ; i++)
    {
        if(S[i]=='R')r++;
        else if(S[i]=='G')g++;
        else b++;
    }
    ll res=r*g*b;
    ll d=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int k=j*2-i;
            if(k>=N||S[k]==S[j]||S[i]==S[j]||S[i]==S[k])continue;
            d++;
        }
    }
    cout << res - d;
}
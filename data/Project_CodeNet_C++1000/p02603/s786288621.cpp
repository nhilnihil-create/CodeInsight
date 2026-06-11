#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll arr[n];
    for (ll i=0;i<n;i++)
        cin>>arr[i];
    ll rem,tmp,cur=1000;
    for (ll i=1;i<n;i++){
        if (arr[i]>=arr[i-1]){
            tmp=cur/arr[i-1];
            rem=cur%arr[i-1];
            cur=(tmp*arr[i])+rem;
        }
    }
    cout<<cur;

    return 0;
}

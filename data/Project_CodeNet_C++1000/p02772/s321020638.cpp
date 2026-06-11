#include <bits/stdc++.h>
using namespace std;

typedef long long  int   ll;
ll a[200];
int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,d5=0,d=0;
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>a[i];}
       for(int i=0;i<n;++i){
        if(a[i]%2==0){d++;
            if(a[i]%5==0||a[i]%3==0)d5++;

        }}
        if(d5==d)cout<<"APPROVED";
        else cout<<"DENIED";

    return 0;
}
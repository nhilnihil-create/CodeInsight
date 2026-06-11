#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n,x,pow=1,cumm=-1,siz=0;
    cin>>n;
    string s;
    while(cumm+pow<n){
        cumm+=pow;
        pow*=26;
        siz++;
    }
    n-=cumm;
    n--;
    for (int i=0;i<siz;i++){
        x=n%26;
        s+=x+'a';
        n/=26;
    }
    reverse(s.begin(),s.end());
    cout<<s;

    return 0;
}

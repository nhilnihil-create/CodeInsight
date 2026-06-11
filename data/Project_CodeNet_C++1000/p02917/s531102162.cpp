#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;
#define w(x) cout << (#x) << " is " << x << "\n" ;

int main()
{
    ll n,i,s=0;
    cin >> n ;
    vector<ll>v(n-1);
    for(auto &it:v)
        cin >> it ;
    if(n==2)
        cout << v[0] + v[0] << "\n";
    else
    {
        for(i=0 ; i <n-2 ; i++)
        {
            s+=min(v[i],v[i+1]);
        }
        s+=v[0];
        s+=v[n-2];
        cout << s << "\n";
    }


}

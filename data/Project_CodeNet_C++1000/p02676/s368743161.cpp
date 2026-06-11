#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if( n>=s.size() )
        cout<< s <<endl;
     else
    {
        for( ll i =0 ; i < n ; i++ )
        {
            cout << s[i];
        }
        cout << "..." <<endl;
    }
}


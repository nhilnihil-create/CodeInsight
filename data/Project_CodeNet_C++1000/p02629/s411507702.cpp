#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int main()
{
    ll n;
    string s = "";
    cin>>n;
    while(n){
        n--;
        s+=char(n % 26 + 'a');
        n /= 26;
    }
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}

/*
    /\ In The Name Of ALLAH /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main()
{
    string s; cin>>s;
    ll sum = 0;
    for(int i = 0;i < s.size();i++) sum += (s[i]-'0');
    if(sum % 9 == 0) cout<<"Yes\n";
    else cout<<"No\n";
}

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    string s;
    cin>>k>>s;
    if(k>=s.size()) cout<<s;
    else {
        cout<<s.substr(0,k) + "...";
    }
    return 0;
}

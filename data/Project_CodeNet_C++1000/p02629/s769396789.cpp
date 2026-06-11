#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    n--;
    vector<char>s;
    s.push_back('a'+(n%26));
    n/=26;
    while(n)
    {
        n--;
        s.push_back('a'+(n%26));
        n/=26;
    }
    for (ll i=0;i<s.size();i++)
        cout << s[s.size()-1-i];
    cout << endl;
	return 0 ; 
}

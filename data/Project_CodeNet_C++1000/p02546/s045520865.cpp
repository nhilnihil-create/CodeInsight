#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define Mod 998244353
#define pi 3.14159265358979323846
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;

int main()
{
    string s;
    cin>>s;
    if(s[s.size()-1]!='s') cout<<s+'s'<<endl;
    else cout<<s+"es"<<endl;
    return 0;
}

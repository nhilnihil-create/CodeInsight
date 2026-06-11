#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

ll ar[200005];

int main()
{
    string s,t,r;
    t="s";
    r="es";
    cin>>s;
    ll a,b;
    a=s.size();
    if(s[a-1]=='s')
    {
        cout<<s<<r<<endl;
    }
    else{
        cout<<s<<t<<endl;
    }
    return 0;
}

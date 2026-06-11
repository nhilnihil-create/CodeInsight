#include <bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x << ": " << x << endl
#define fo(i, n) for (ll i = 0; i < n; i++)
#define fkn(i, k, n) for (i = k; i < n; i++)
#define ll long long
#define F first;
#define S second;
#define PB(x) push_back(x);
#define MP(x,y) make_pair(x,y);
typedef vector<ll> vll;

bool powerOfTwo(ll x)
{
    return !(x & (x - 1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int i=0;
    while(a > 0 && c>0)
    {
        //cout<<a<<" "<<c<<endl;
        if(!(i&1))
        {
        c-=b;

        }
        else{
            a-=d;
        }
        i++;

    }
     if (a>0)
    
            cout << "Yes";
        else{
        cout<<"No";
    }
    

}


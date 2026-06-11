#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define mod 1000000007
#define inf 1e18+42
#define endl "\n"
#define pi 3.1415926535897932384626433832795028841971693993751058
#define maxn 100005

#define out1(a) cout<<#a<<" "<<a<<endl
#define out2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define out3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define fori(it,A) for(auto it=A.begin();it!=A.end();it++)

#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define all(x) (x).begin(),(x).end()
#define zero(x) memset(x,0,sizeof(x));
#define ceil(a,b) (a+b-1)/b
 
using namespace std;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//START OF CODE ->->->->->->->

void solve()
{
    int x;
    cin>>x;
    if ( x >= 400 && x < 600 ){
        cout<<"8"<<endl;
    }
    else if ( x < 800 && x >= 600 ){
        cout<<"7"<<endl;
    }
    else if ( x >= 800 && x < 1000 ){
        cout<<"6"<<endl;
    }
    else if ( x >= 1000 && x < 1200 ){
        cout<<"5"<<endl;
    }
    else if ( x >= 1200 && x < 1400 ){
        cout<<"4"<<endl;
    }
    else if ( x >= 1400 && x < 1600 ){
        cout<<"3"<<endl;
    }
    else if ( x >= 1600 && x < 1800 ){
        cout<<"2"<<endl;
    }
    else if ( x >= 1800 && x < 2000 ){
        cout<<"1"<<endl;
    }

}

//END OF CODE ->->->->->->->->

signed main()
{
    fast;
    int t = 1;
    // cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}


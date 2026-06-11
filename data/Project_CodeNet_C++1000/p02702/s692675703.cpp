/*
Hey there stalker....

█▀▀▄░░░░░░░░░░░▄▀▀█
░█░░░▀▄░▄▄▄▄▄░▄▀░░░█
░░▀▄░░░▀░░░░░▀░░░▄▀
░░░░▌░▄▄░░░▄▄░▐▀▀
░░░▐░░█▄░░░▄█░░▌▄▄▀▀▀▀█
░░░▌▄▄▀▀░▄░▀▀▄▄▐░░░░░░█
▄▀▀▐▀▀░▄▄▄▄▄░▀▀▌▄▄▄░░░█
█░░░▀▄░█░░░█░▄▀░░░░█▀▀▀
░▀▄░░▀░░▀▀▀░░▀░░░▄█▀
░░░█░░░░░░░░░░░▄▀▄░▀▄
░░░█░░░░░░░░░▄▀█░░█░░█
░░░█░░░░░░░░░░░█▄█░░▄▀
░░░█░░░░░░░░░░░████▀
░░░▀▄▄▀▀▄▄▀▀▄▄▄█▀

Like what you see?
*/
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define pii         pair<ll ,ll>
#define vi          vector<ll>
#define present(container, element) (container.find(element) != container.end()) /* For set n maps */
#define cpresent(container, element) (find(all(container),element) != container.end()) /* For vectors */
#define all(a)      (a).begin(),(a).end()
#define invect(data,n,commands) for(int i = 0;i<n;i++){int tmp;cin>>tmp;data.pb(tmp);commands}
#define inset(data,n,commands) for(int i = 0;i<n;i++){int tmp;cin>>tmp;data.I(tmp);commands}
#define F           first
#define S           second
#define I           insert
#define sz(x)       (ll)x.size()
#define rep(i,a,b)    for(ll  i=a;i<b;i++)
#define repr(i,a,b) for(ll  i=a;i>b;i--)
#define trav(a, x) 	for(auto& a : x)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lcase(a) (char)tolower(a)
#define ll long long int
#define lld long double
#define endl "\n"
#define PI 3.14159265358979323844
#define MOD 1000000007
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
const int N = 1e5 + 5;
/*	For Debugging	*/
#define DEBUG 		cerr<<"\n>>>I'm Here<<<\n"<<endl;
#define display(x) trav(a,x) cout<<a<<" ";cout<<endl;
#define what_is(x)  cerr << #x << " is " << x << endl;

ll modexp(ll a,ll b,ll m)
{
    ll r=1;
    a=a%m;
    while(b>0)
    {
        if(b&1)r=(r*a)%m;
        b = b>>1;
        a=(a*a)%m;
    }
    return r%m;
}

int32_t main()
{
   IOS

    int TESTS=1;
    //cin >> TESTS;
    while (TESTS--)
    {
        string s;
        cin>>s ;

        reverse(all(s));
        ll n=sz(s);
        vi v(n);
        rep(i,0,n)
        {
            v[i]=((s[i]-'0')*modexp(10,i,2019))%2019;
            //what_is(v[i]);
        }
        vi pref(n);
        pref[0]=v[0];
        rep(i,1,n)
        {
            pref[i]=(pref[i-1]+v[i])%2019;
           // what_is(pref[i]);
        }
        ll ans=0;
        map<ll,ll>mp;
        rep(i,0,n)
        {
            if(pref[i]==0)
            {
               ans++;
            }
            ans+=mp[pref[i]];
            mp[pref[i]]++;
        }
        cout<< ans << endl;



    }
    return 0;
}

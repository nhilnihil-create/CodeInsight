

#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list> 
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<set>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define ll long long
#define ld long double
#define pb push_back
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>
#define pll pair<long long,long long>
#define mp make_pair
#define B begin()
#define E end()
#define S size()
#define m9 1000000007
using namespace std;


 
/*
string fs(string str1, string str2)
{    if (str1.length() > str2.length())
        swap(str1, str2);
      string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
      int carry = 0;
      for (int i=n1-1; i>=0; i--)
    {
 
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
      for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
      if (carry)
        str.push_back(carry+'0');
      reverse(str.begin(), str.end());
 
    return str;
}*/
 
ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}
 
/*
ll gcdextended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; 
    int gcd = gcdextended(b%a, a, &x1, &y1); 
   
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
 
 
///RELATIVE COPRIME
ll modinverse(ll a, ll m) 
{ 
    ll x, y; 
   ll g = gcdextended(a, m, &x, &y); 
    if (g != 1) 
return -1;
    else
    { 
        ll res = (x%m + m) % m; 
        return res;  
    } 
} 
  */
ll powmod(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = powmod(x, y/2, m) % m; 
    p = (p * p) % m; 
    return (y%2 == 0)? p : (x * p) % m; 
} 
///M IS PRIME
ll modif(ll x,ll m){
return(powmod(x,m-2,m));
 
}
 
bool fa(vll &x,vll &y){return x[0]<y[0];}
bool fa1(vll &x,vll &y){return x[1]<y[1];}
bool f1(pll &x,pll &y){return x.second<y.second;}
bool f2(pll &x,pll &y){return x.first>y.first;}
bool f3(ll &x,ll &y){
    return x>y; 
    }

#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define pin(a) for(auto x:a)cout<<x<<" ";cout<<endl
#define fck(a) cout<<a;exit(0)
#define vvll vector<vector<ll> >
#define A(b) b.begin(),b.end()


//include<bits/stdc++.h>


int main()
{ fastio;
// freopen("input.txt", "r", stdin); 
// freopen("output.txt", "w", stdout);
vll ans;
vvll temp(2);
forl(i,1,10){
    ans.pb(i);
    temp[1].pb(i);
}
ll m=1e5+1;
forl(i,0,100000){
if(ans.S>m)break;
temp[i%2].clear();
ll h=(i+1)%2;
for(auto x:temp[h]){
    ll r=x%10;
    ll e=max(r-1,0ll);
    ll f=min(9ll,r+1);
    for(ll t=e;t<=f;t++){
            ll g=x;
            g*=10;
            g+=t;
           // p1(g);
            temp[i%2].pb(g);
            ans.pb(g);
    }
}

}
//forl(i,0,20){p0(ans[i]);}
ll n;cin>>n;
n--;
cout<<ans[n];

return 0;
}



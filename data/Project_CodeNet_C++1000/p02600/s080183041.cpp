#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define mp make_pair
#define F first
#define S second 
#define pl pair<long ,long >
#define pi pair<int ,int >
#define lb(v,x) lower_bound(v.begin(),v.end(),x)-v.begin();
#define ub(v,x) upper_bound(v.begin(),v.end(),x)-v.begin();
#define ct(i) cout<< i << "\n";
#define sv(v) sort(v.begin(),v.end());
#define mod 1000000007
#define M 100005
vector<int> ans;
int a,b,c,m;

void answer(){
    ll n;
    cin>>n;
    if(n>=400 && n<=599) cout<<8;
    if(n>=600 && n<=799) cout<<7;
    if(n>=800 && n<=999) cout<<6;
    if(n>=1000 && n<=1199) cout<<5;
    if(n>=1200 && n<=1399) cout<<4;
    if(n>=1400 && n<=1599) cout<<3;
    if(n>=1600 && n<=1799) cout<<2;
    if(n>=1800 && n<=1999) cout<<1;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    int q;
    //cin>>q; while(q--)
        answer();

    return 0;
}

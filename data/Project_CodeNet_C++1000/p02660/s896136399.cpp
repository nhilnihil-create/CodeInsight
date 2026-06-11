/**Bismillahir Rahmanir Raheem
    Author:Refatul Fahad**/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N = 1e6;
const ll M = (ll)1e9 + 7;
const double pi=2*acos(0.0);
const double esp=1e-9;
int Set(int N,int pos) {
    return N=N | (1<<pos);
}
int reset(int N,int pos) {
    return N= N & ~(1<<pos);
}
bool check(int N,int pos) {
    return (bool)(N & (1<<pos));
}

int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};


map<int,int> cnt;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);

    int test=1;
    //cin>>test;

    for(int cs=1; cs<=test; ++cs) {
        ll n,num,ans=0;
        cin>>n;
        int sqrtn=sqrt(n);
        num=n;
        for(ll i=2; i<=sqrtn; ++i) {
            if(num%i==0) {
                while(num%i==0) {
                    num/=i;
                    cnt[i]++;
                }
            }
        }
        for(auto x:cnt) {
            int ct=x.second,sb=1;
            while(ct>=sb) {
                ans++;
                ct-=sb;
                ++sb;
            }
        }
        if(num!=1ll) {
            cout<<ans+1<<endl;
        } else {
            cout<<ans<<endl;
        }
    }
    return 0;
}


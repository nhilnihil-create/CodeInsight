#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define mp make_pair
#define endl "\n"
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define lb lower_bound
#define forn(i,n) for(ll i=0 ; i<n ; i++)
#define arr(a,n) for(ll i=0;i<n;i++){ cin>>a[i]; }
#define ub upper_bound
#define pb push_back
#define pi pair<int,int>
#define mod 1000000007
#define vectormax *max_element
#define vectormin *min_element
#define arraysize 1000000
#define setbit _builtin_popcountll
using namespace std;

ll ipow(ll x, ll n)
{
    ll result = 1;
    while (n) {
        if (n & 1)
            result = result * x ;
        n = n / 2;
        x = x * x;
    }
    return result;
}
int main(){
 int r,g,b;
 cin>>r>>g>>b;
int k;
cin>>k;
int count=0;
if(r>=g){
    while(1){
        if(g>r)
            break;
        g=g*2;
        count++;
    }
}
if(g>=b){
    while(1){
        if(b>g)
            break;
        b=b*2;
        count++;
    }
}
if(count>k)
    cout<<"No"<<endl;
else
    cout<<"Yes"<<endl;
return 0;
}

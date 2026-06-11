/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

int main()
{
    int n;
    string s;
    cin>>n>>s;
    vector<int> w,r;
    for(int i=0;i<n;i++){
        if(s[i]=='W') w.pb(i);
        else r.pb(i);
    }
    reverse(r.begin(),r.end());

    int i=0,j=0,x=w.size(),y=r.size();
    int cnt=0;
    while(i<x && j<y && w[i]<r[j]){
        i++;
        j++;
        cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}



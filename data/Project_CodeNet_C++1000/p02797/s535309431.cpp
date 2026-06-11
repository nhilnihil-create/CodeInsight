#include<bits/stdc++.h>
#define inf 2000000000
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define rng_23 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int,int> mii;
int ara[100000];
int main()
{
    int i,j;
    int n,k,s;
    cin>>n>>k>>s;
    if(k==n){
        for(i=0;i<n;i++)
            ara[i]=s;
    }
    else if(k==0){
        for(i=0;i<n;i++)
            ara[i]=232313243;
    }
    else if(s==1){
        for(i=0;i<k;i++)
            ara[i]=1;
        while(i<n)
            ara[i++]=1e9;
    }
    else if(s<1e9){
        ara[0]=1;
        for(i=1;i<=k;i++){
            if(i&1)
                ara[i]=s-1;
            else
                ara[i]=1;
        }
        while(i<n)
            ara[i++]=1e9;
    }
    else {
        ara[0]=1;
        for(i=1;i<=k;i++){
            if(i&1)
                ara[i]=s-1;
            else
                ara[i]=1;
        }
        while(i<n)
            ara[i++]=2;
    }
    for(i=0;i<n;i++)
        cout<<ara[i]<<" ";
}

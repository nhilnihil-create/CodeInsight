#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <fstream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
using namespace std;
#define ll           long long
#define all(v)       (v).begin() , (v).end()
#define vi           vector <ll>
#define vii          vector <pair<ll,ll>>
#define ii           pair<ll,ll>
#define sz(v)	     ((int)((v).size()))
#define lp(i,a,b)    for(int i=a;i<b;i++)
#define pb           push_back
#define pf           push_front
#define F            first
#define S            second
#define endl         "\n"
#define IOS          ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI = 3.14159265358979323846;
const ll inf=2e9,MOD=1e9+7,MAX=1e5+1;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m,k,mx=0;
    cin>>n>>m>>k;
    ll a[n],b[m];
    lp(i,0,n)
        cin>>a[i];
    lp(i,0,m){
        cin>>b[i];
        if(i)
            b[i]+=b[i-1];
        if(b[i]<=k)
            mx=i+1;
    }
    ll sum=0;
    lp(i,0,n){
        sum+=a[i];
        if(sum<=k){
            int l=0,r=m-1,mid,val=k-sum;
            while(l<=r){
                mid=(l+r)/2;
                if(b[mid]<=val)
                    l=mid+1;
                else
                    r=mid-1;
            }
            mx=max(mx,l+i+1);
        } else
            break;
    }
    cout<<mx;
}
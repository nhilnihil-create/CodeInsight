#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define int long long
#define pb push_back
#define pll pair<long long,long long>
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h1,m1,h2,m2;
    cin>>h1>>m1>>h2>>m2;
    int f=h1*60+m1;
    int l=h2*60+m2;
    int k;
    cin>>k;
    cout<<(l-f)-k;
    return 0;
}
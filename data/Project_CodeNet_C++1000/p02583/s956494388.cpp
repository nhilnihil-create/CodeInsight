#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pii make_pair
#define pb push_back
int ceil(int a, int b) { if(a%b==0) return a/b; else return a/b+1; }
bool checkbit(int pos, int mask) { return mask&(1<<pos); }
int turnon(int pos, int mask) { return mask|(1<<pos); }

main()
{
    fastio;
    int n;
    cin>>n;
    int a[n];
    map<int, int>mp;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a, a+n);
    int res=0;
    for(int i=0; i<n; i++) {
        for(int j=i+1 ; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(a[i]!=a[j] && a[k]<a[i]+a[j] && a[k]!=a[i] && a[k]!=a[j]) res++;
            }
        }
    }
    cout<<res;
}

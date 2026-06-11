#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pii make_pair
#define pb push_back
#define ff first
#define ss second
int ceil(int a, int b) { if(a%b==0) return a/b; else return a/b+1; }
bool checkbit(int pos, int mask) { return mask&(1<<pos); }
int turnon(int pos, int mask) { return mask|(1<<pos); }

main()
{
    fastio;
    int n, a, b, cnt=0, fl=0;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a>>b;
        if(a==b) cnt++;
        else cnt=0;
        if(cnt==3) {
            fl=1;
        }
    }
    if(fl) cout<<"Yes";
    else cout<<"No";
}

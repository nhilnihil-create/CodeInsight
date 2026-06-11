#include <bits/stdc++.h>

using namespace std;
#define ll long long int


int main()
{
    int n,k,c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> ans;
    vector<int> dpl(n),dpr(n),cand;
    int last = -10000000;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'x') dpl[i] = dpl[i - 1];
        else if (last + c < i) {
            last = i;
            dpl[i] = dpl[i - 1] + 1;
        }
        else dpl[i] = dpl[i - 1];
    }
    last = -10000000;
    for (int i = 1; i <= n; ++i) {
        if (s[n - i] == 'x') dpr[i] = dpr[i - 1];
        else if (last + c < i) {
            last = i;
            dpr[i] = dpr[i - 1] + 1;
        }
        else dpr[i] = dpr[i - 1];
    }
    for(int i=0;i<n;i++){
        int l = i;
        int r = n-i-1;
        if(s[i]=='o' && dpl[l]+dpr[r]<k &&  dpl[l]+dpr[r]+1>=k) cout << (i+1) << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,c; cin >> n >> k >> c;
    string s; cin >> s;

    vector<int> ans;

    int l[k+1],r[k+1];

    int cur = 1;
    int i = 0;
    while(i<n){
        if(cur>k) break;
        if(s[i] == 'x'){
            i++;
            continue;
        }
        l[cur] = i;
        i += (c+1);
        cur++;
    }

    cur = k;
    int j = n-1;
    while(j>=0){
        if(cur == 0) break;
        if(s[j] == 'x'){
            j--;
            continue;
        }
        r[cur] = j;
        j -= (c+1);
        cur--;
    }

    for(int i=1;i<=k;i++){
        if(l[i] == r[i]){
            cout << l[i]+1 << "\n";
        }
    }



}

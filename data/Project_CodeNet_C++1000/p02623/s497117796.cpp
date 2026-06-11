#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int n,m,k,tmp;
int a[200000];
int b[200000];



void solve(){
    
    cin >> n >> m >> k;

    int last = 0;
    int maxn = n-1;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[i] = last+tmp;
        last = a[i];
        if(last > k && maxn == n-1) maxn = i-1;
    }
    int maxm = m-1;
    last = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        b[i] = last+tmp;
        last = b[i];
        if(last > k && maxm == m-1) maxm = i-1;
    }

    int ans = max(maxn+1,max(maxm+1,0));
    int sum = 0;
    int curm = 0;
    for (int i = maxn; i >=0; i--)
    {
        sum = a[i] + b[curm];
        while(sum < k && curm < (m-1)){
            curm++;
            sum = a[i] + b[curm];
        }

        if(curm == m-1 && sum <= k){
            ans = max(curm+i+2,ans);
        }
        else{
            ans = max(curm-1+i+2,ans);
        }
    }
    
    cout << ans << endl;

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}
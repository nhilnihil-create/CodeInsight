#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int n;
int a[1000001];
int inp[200001];

void solve(){

    cin >> n;

    for (int i = 0; i < 1000001; i++)
    {
        a[i] = 0;
    }
    
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }
    
    sort(inp, inp+n);

    int max = inp[n-1];

    for (int i = 0; i < n; i++)
    {
        int x = inp[i];
        //cout << "i: " << i << endl;
        if(a[x] == 1){
            a[x] +=1;
            continue;
        }
        for (int j = x; j <= max; j = j+x)
        {
            
            a[j] += 1;
        }
        
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[inp[i]] == 1) ans++;
    }
    
    
    cout << ans << endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}
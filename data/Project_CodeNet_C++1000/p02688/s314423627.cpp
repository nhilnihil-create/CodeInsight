#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L

int a[101];
int n,k,d,t;

void solve(){

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    

    for (int i = 0; i < k; i++)
    {
        cin >> d;

        for (int h = 0; h < d; h++)
        {
            cin >> t;
            t--;
            a[t] = 1;
        }
        
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] ==0 ) ans++;
    }
    
    cout << ans << endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}
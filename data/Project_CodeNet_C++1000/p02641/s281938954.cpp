#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int x, n;
int a[101];


void solve(){

    cin >> x >> n;

    for (int i = 0; i < 100; i++)
    {
        a[i] = 0;
    }
    

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[tmp] = 1;
    }
    
    int upper = 101;
    for (int i = x; i <= 100; i++)
    {
        if(a[i] == 0){
            upper = i;
            break;
        }
    }
    
    int lower = 0;
    for (int i = x; i > 0 ; i--)
    {
        if(a[i] == 0){
            lower = i;
            break;
        }
    }
    
    int ans;
    if( (x - lower) <= (upper-x)){
        ans = lower;
    }
    else{
        ans = upper;
    }

    cout << ans << endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}
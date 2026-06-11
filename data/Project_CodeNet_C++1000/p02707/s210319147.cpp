#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L

int a[200004];
int n,aa;

void solve(){

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    

    for (int i = 1; i < n; i++)
    {
        cin >> aa;
        aa--;
        a[aa]++;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array


int n,t;
int a[200000];

void solve(){
    
    cin >> n;

    int sum;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i == 0) sum = a[0];
        else{
            sum = sum ^ a[i];
        }
    }
    

    for (int i = 0; i < n; i++)
    {
        cout << (sum ^ a[i]) << " ";
    }
    cout << endl;

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ll n,m;
    cin >> n >> m;
    if(n%2==1){
        for(int i=1;i<=m;i++){
            cout << i << " " << (n-i) << endl;
        }
    }
    else{
        int k = (m+1)/2;
        for(int i=1;i<=k;i++){
            cout << i << " " << (n-i+1) << endl;
        }
        for(int i=k+1;i<=m;i++){
            cout << i << " " << (n-i) << endl;
        }
    }
}

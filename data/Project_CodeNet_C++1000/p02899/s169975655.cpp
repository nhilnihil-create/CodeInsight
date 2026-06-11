#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

    int main (){
        int n;
        cin >> n;
        vector<int> a(n+1);
        
        rep(i,n){
            int x;
            cin >> x;
            a[x]=i;
        }
        
        rep(i,n){
            cout << a[i] << endl;
        }
        

    }
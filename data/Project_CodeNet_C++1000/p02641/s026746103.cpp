#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

int occur[200];

int main(){
    AC
    int x, n;
    cin>>x>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        occur[x] = 1;
    }

    if(!occur[x]){
        cout<<x<<nl;
        return 0;
    }

    int ans = 500;
    int idx = 500;
    for(int i=0; i<=101; i++){
        if(!occur[i] && abs(i-x)<ans){
           ans = abs(i-x);
           idx = i; 
        }
    }
    cout<<idx<<endl;
}
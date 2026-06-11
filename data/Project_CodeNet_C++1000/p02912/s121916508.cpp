#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;
// int A[N];

void sol(){
    int n , m ; cin >> n >> m ;
    priority_queue<int> A;
    for(int i = 0 ; i < n ; ++i){
        int a ; cin >> a;
        A.push(a);
    }
    while(m--){
        int a = A.top();
        A.pop();
        a /= 2;
        A.push(a);    
    }
    int ans =0 ;
    while(!A.empty()){
        ans += A.top();
        A.pop();
    }
    cout << ans << endl;
}

int32_t main(){
    fast;
    int t = 1; 
    // cin >> t; 
    while(t--) sol();    
    return 0;
}
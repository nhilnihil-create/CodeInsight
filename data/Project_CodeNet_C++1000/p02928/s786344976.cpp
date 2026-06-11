#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77 , M = 1e9+7;
int A[N] , C[N];
string s;

int32_t main(){
    fast;
    int n , k ; cin >> n >> k ;
    for(int i = 0 ; i < n ; ++i) cin >> A[i];
    int ans = 0;
    
    for(int i = 0 ; i < n ;++i){
        int a , b ;
        a = b = 0;
        for(int j= 0 ; j < i ; ++j) if(A[j]>A[i]) a++;
        b = a;
        for(int j = i+1 ; j < n ; ++j) if(A[j] > A[i]) b++;
        ans = (ans + (k*(k-1)/2)%M * b%M +a*k)%M;
    }
    cout << ans << endl;
    return 0;
}
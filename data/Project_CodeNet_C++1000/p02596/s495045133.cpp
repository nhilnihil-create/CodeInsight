#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REV(i,a,n) for(int i=a;i>=n;i--)
#define all(a) a.begin(),a.end()
const int NUM = 2e5 + 5;

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int num_tests=1; 
    //cin >> num_tests;
    while(num_tests-->0){
        int n; cin >> n;
        int dig = 0,rem = 7;
        while(dig < 1e7){
            dig++;
            if(rem%n == 0){
                cout << dig ;
                return 0;
            }
            rem = (rem*10 + 7) % n;
        }
        cout << -1 ;
    }    
}
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define endl "\n"
const int MOD=1e9+7;
#ifndef HOME
#define cerr if(0)cerr
#endif
vector<int> getDivisors(int n) 
{   
    vector<int>v;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i){
                v.push_back(i);
            }else{
                 v.push_back(i);
                 v.push_back(n/i);
            }
        } 
    }
    return v; 
}
bool check(int x,int y){
    if(y == 1) return false;
    while(x % y == 0){
        x /= y;
    }
    return x%y == 1;
} 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>v = getDivisors(n-1);
    int x = getDivisors(n-1).size() - 1;
    int y = 0;
    for(int i=1;i*i<=n;i++){
        if(n % i == 0){
            if(n / i == i){
                y += check(n,i);
            }else{
                y += check(n,i);
                y += check(n, n / i);
            }
        }
    }
    cout<<x+y;
    return 0;
    
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const int MOD = 1000000007;
ll cnt =0,ans=0;

int main(){
    int n;
    cin >> n;
    if(n%1000!=0)
    cout << 1000 - n%1000 << endl;
    else cout << 0 << endl;
}
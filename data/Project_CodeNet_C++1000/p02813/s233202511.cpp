#include<bits/stdc++.h>
#include<vector>
#define inf 10000000000000
#define ll unsigned long long
#define boostUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fsr(i,n) for(ll i=0;i<n;i++)
#define fcr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])
#define mod 1000000007;

using namespace std;
// lower_bound
// it returns pos of the elmnt which is not less then the query elmnt

int main() {
    int n; cin >> n;
    vector<int>v(n,0),p(n,0),q(n,0),tmp(n,0);
    for(int i = 0; i < n; i++){
        v[i] = i+1;
        tmp[i] = i+1;
        cin >> p[i];
    }
    for(int i = 0; i < n; i ++)
        cin >> q[i];
    int count = 1, a=1,b=1, flag = 0;
    while(next_permutation(v.begin(),v.end())){
        count++;
        if(v==p){
            a = count;break;
        }
    }
    count = 1;
    while(next_permutation(tmp.begin(),tmp.end())){
        count++;
        if(tmp==q){
            b = count;break;
        }
    }
    cout << abs(a-b) << endl;
}




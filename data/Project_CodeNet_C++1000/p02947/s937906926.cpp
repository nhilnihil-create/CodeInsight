#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define forn(b) for(int i = 0; i < b; i++)
#define rforn(b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
    
int main(){
    speed;
    int t; cin >> t; 
    string s = "aaaabaaaaa";
    map<string,int> hash;
    while(t--) {
        char a[10];
        forn(10) {
            cin >> a[i];
        }
        sort(a, a + 10);
        for(int i = 0; i < 10; i++) {
            s[i] = a[i];
        }
        hash[s]++;
    }   
    ll res = 0;
    It(hash) {
        if(it->second != 1) {
            int n = it->second - 1;
            res += (n + pow(n,  2)) / 2;
        }
    }   
    cout << res;
    return 0;
}
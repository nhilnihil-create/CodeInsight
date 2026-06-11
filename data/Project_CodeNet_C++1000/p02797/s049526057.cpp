#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    int n, k, s;
    cin >> n >> k >> s;
    int x;
    if(s==1e9)
        x = 1;
    else
        x = s+1;

    for(int i=0; i<k; ++i){
        cout << s << " ";
    }
    for(int i=0; i<n-k; ++i){
        cout << x << " ";
    }
}

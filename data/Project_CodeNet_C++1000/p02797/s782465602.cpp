#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,k,s;
    cin >> n >> k >> s;
    int inf = 1e9;
    if(s == inf) inf--;
    for(int i = 0; i < k; i++) cout << s << " ";
    for(int i = 0; i < n-k; i++) cout << inf << " ";
    cout << endl;
    return 0;
}
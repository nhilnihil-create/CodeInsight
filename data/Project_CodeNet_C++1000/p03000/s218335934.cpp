#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<long long,long long> pll;

int main() {
    fastIO;
    int n, x, ind;
    cin >> n >> x;
    int dist[n+1], prefix[n+1];
    dist[0] = 0, prefix[0] = 0;
    for(int i = 1; i < n+1; i++){
        cin >> dist[i];
    }
    for(int i = 1; i < n+1; i++){
        prefix[i] = dist[i] + prefix[i-1];
    }
    ind = upper_bound(prefix,prefix+n+1, x)-prefix;
    cout << ind << endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int a, b, c, d, f;
    cin >> a >> b >> c >> d >> f;

    if (a == 0){
        cout << 1 << "\n";
    }else if (b == 0){
        cout << 2 << "\n";
    }else if (c == 0){
        cout << 3 << "\n";
    }else if (d == 0){
        cout << 4 << "\n";
    }else if (f == 0){
        cout << 5 << "\n";
    }
    
    

    return 0;
}

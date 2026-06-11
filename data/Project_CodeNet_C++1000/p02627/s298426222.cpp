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

    char a;
    cin >> a;

    if('A' <= a && a <= 'Z'){
        cout << 'A' << "\n";
    }else{
        cout << 'a' << "\n";
    }


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define cw(x) cout << (x) << endl
#define cww(x,y) cout << (x) << ' ' << y << endl
#define cwa(x) for(auto a:x) cout << a << ' ';cout << endl
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef unordered_set<int> usi;
typedef vector<pi> vpi;

int x,i;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    for(cin >> x,i=x;i%360!=0;i+=x){}
    cout << i/x << endl;

    return 0;
}

// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e6 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    string s;
    cin >> s;
    bool a = 0, b = 0, c = 0;
    for(int i = 0; i < n; i++){
	a|= s[i] == '2';
	b^= s[i] == '2' && ((n-1) & i) == i;
	c^= s[i] == '3' && ((n-1) & i) == i;
    }
    if(b)
	return cout << 1 << endl, 0;
    if(a)
	return cout << 0 << endl, 0;
    if(c)
	return cout << 2 << endl, 0;
    else
	return cout << 0 << endl, 0;
}

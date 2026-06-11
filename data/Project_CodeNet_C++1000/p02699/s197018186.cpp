#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;
#define pb push_back
#define mp make_pair
#define all(c) ((c).begin(), (c).end)
#define sz(a) int((a).size())
#define tr(c,i) for(typeof(c).begin() i = (c).begin();it!=(c).end();it++)
#define present(c,x) ((c).find(x)!=(c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end)
#define cp(s,c) copy(all(c),(s).begin())
// note that data is copied from C --> S's reference

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int s, w;
    cin >> s >> w;
    cout << ((w >=s)?"unsafe":"safe") << endl;
    return 0;
}
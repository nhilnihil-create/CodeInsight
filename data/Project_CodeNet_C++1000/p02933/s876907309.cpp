#include<bits/stdc++.h>
#include<limits>
#define ll long long
#define F first
#define S second
#define pb push_back
#define oo (1LL<<63-1)
#define endl '\n'
#define si size()
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define Matrix vector< vector < long long > >

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

const long double Pi=acos(-1),e=2.718;
const int N=2e5+10, mod=1e9+7;


int main ()
{
    FASTIO
    int a;
    string s;
    cin >> a >> s;
    if(a>=3200){
        cout << s << endl;
    }
    else {
        cout << "red" << endl;
    }
    return 0;
}
/**

*/

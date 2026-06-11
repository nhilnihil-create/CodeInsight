#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;



int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h1,h2,m1,m2,k;
    cin>>h1>>m1>>h2>>m2>>k;
    int hour = (h2-h1)*60;
    int min = m2-m1;
    hour = hour + min;
    if(hour-k>0){
        cout<<hour-k;
    }
    else{
        cout<<"0";

    }



    return 0;
}

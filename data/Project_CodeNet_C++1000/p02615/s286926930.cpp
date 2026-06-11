#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define FILL0(x) memset(x,0,sizeof(x))
#define FILL1(x) memset(x,-1,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    vector<ll> vec(n);

    rep(i, n)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    int cnt=0;

    ll sum=vec[0];
int i=1;
    for(;i<n/2; i++)
    {
        sum+=vec[i]*2;
    }

    if(n%2==1) sum+=vec[i]; 


    cout << sum << endl;








    return 0;

}

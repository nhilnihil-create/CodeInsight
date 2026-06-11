#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define mp make_pair
#define INF 1e9

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
}

int main()
{
    init();
    ll n;
    cin >> n;

    int c=0;
    for(int a=1;a<n;a++){
        if(a*a>=n)break;
        for(int b=a;b<n;b++){
            if(a*b<n){
                if(a==b)c++;
                else c+=2;
            }
        }
    }
    cout<<c<<endl;


}

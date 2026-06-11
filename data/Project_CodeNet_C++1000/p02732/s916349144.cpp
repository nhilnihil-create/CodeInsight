#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
// scanf("%d %d %d %d", &w, &b, &d, &s); %lld
// printf("%d\n", points);
// const double PI = acos(-1);

int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    #else
        fastIO;
    #endif
        ll n, aux, temp;
        ll ans = 0, rta = 0;
        map <int, pll> m;
        cin >> n;
        int num[n];
        for(int i = 0; i<n; i++){
            cin >> aux;
            num[i] = aux;
            m[aux].sd+=(m[aux].ft);
            m[aux].ft++;
        }

        for(auto &x: m)
            rta += x.sd.sd;

        for(int i = 0; i<n; i++){
            aux = num[i];
            temp = m[aux].ft-2;
            temp = ((temp*temp+temp)/2);
            ans = rta-m[aux].sd + temp;
            cout << ans << endl;
        }
        return 0;
}
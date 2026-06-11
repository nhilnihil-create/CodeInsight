//#include <tourist>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <tuple>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
struct edge {
    int to, cost;
};
ll n, k;
vector<ll> a;
//約数列挙オーダー√n
vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i=1;i*i<=n;i++)
    if(n%i==0){
        res.push_back(i);
        if(i!=n/i)res.push_back(n/i);
    }
    return res;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>k;
    ll sumt=0;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
        sumt+=temp;
    }
    vector<ll> v=divisor(sumt);
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++){
        vector<ll> amari;
        for(int j=0;j<a.size();j++){
            amari.push_back(a[j]%v[i]);
            //cout<<a[j]%v[i]<<"\n";
        }
        sort(ALL(amari));
        vector<ll> sum, sumr;
        sum.push_back(0);
        sumr.push_back(0);
        ll suma=0;
        ll sumar=0;
        for(int j=0;j<n;j++){
            suma+=amari[j];
            sum.push_back(suma);
            if(amari[j]!=0)
            sumar+=v[i]-amari[j];
            sumr.push_back(sumar);
            //cout<<sumar<<"\n";
        }
        for(int j=0;j<=n;j++){
            //cout<<sum[j]<<" "<<sumr[n]-sumr[j]<<"\n";
            if(sum[j]==sumr[n]-sumr[j]){
                if(sum[j]<=k){
                    return cout<<v[i]<<"\n",0;
                }
            }
        }
    }
    cout<<-1<<"\n";
}


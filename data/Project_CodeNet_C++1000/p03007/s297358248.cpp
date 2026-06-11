//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18) + 1;
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll n;
vector<ll> a;
priority_queue<ll,vector<ll>, greater<ll>> quep,quem;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    ll zerocount=0;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
        if(temp>=0)
        quep.push(temp);
        if(temp<0)
        quem.push(-temp);
    }
    sort(ALL(a));
    vector<ll> ansp,ansm;
    if(n==2){
        cout<<a[1]-a[0]<<"\n";
        cout<<a[1]<<" "<<a[0]<<"\n";
        return 0;
    }
    if(quep.empty()){
        ll temp=quem.top();
        quem.pop();
        ll temp1=quem.top();
        quem.pop();
        ansp.push_back(-temp);
        ansm.push_back(-temp1);
        quep.push(temp1-temp);
    }
    if(quem.empty()){
        ll temp=quep.top();
        quep.pop();
        ll temp1=quep.top();
        quep.pop();
        ansp.push_back(temp1);
        ansm.push_back(temp);
        quem.push(temp1-temp);
    }
        while(true){
        if(quep.size()==1){
            if(quem.empty())break;
                ansp.push_back(quep.top());
                ansm.push_back(-quem.top());
                ll temp=quep.top()+quem.top();
                quep.pop();
                quem.pop();
                quep.push(temp);
        }
        else{
            ansp.push_back(-quem.top());
            ansm.push_back(quep.top());
            ll temp=quep.top()+quem.top();
            quep.pop();
            quem.pop();
            quem.push(temp);
        }
        }
    cout<<quep.top()<<"\n";
    rep(i,ansp.size())
    cout<<ansp[i]<<" "<<ansm[i]<<"\n";
}

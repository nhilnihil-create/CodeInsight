#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238463;
const int MAXN = 200005;
bool isPrime[MAXN];
vector<int> pr;
vector<int> ans;
void sieve()
{
    memset(isPrime, 1, sizeof isPrime);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= MAXN; i += 1 + (i & 1))
    {
        if (isPrime[i])
        {

            for (int j = i * i; j < MAXN; j += i)
                isPrime[j] = 0;
        }
    }
    for(int i=0; i<MAXN; i++)
    {
        if(isPrime[i])
        {

            ans.push_back(i);
        }
    }
}

ld power(ld x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

void debug_out()
{
    cerr << endl;
}

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << H;
    debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


int main()
{
    FAST
    int n;
    cin>>n;
    map<int,int> vis;
    int arr[n];
    for(int i=0;i<n;i++)
        {

            cin>>arr[i];
            vis[arr[i]]++;
        }
    sort(arr,arr+n);
    map<int,int>m;
    for(int i=0;i<n;i++){
        if(vis[arr[i]]>1){
            m[arr[i]]++;
            continue;
        }
        for(int j=1;j*j<=arr[i];j++){
            if(arr[i]%j==0){
                if(vis[j] && j!=arr[i]){
                    m[arr[i]]++;
                }
                if(vis[arr[i]/j] && arr[i]/j != arr[i]){
                    m[arr[i]]++;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(!m[arr[i]]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (ll i = 0; i < n; i++)
#define forr(i,a,b) for (ll i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const ll MX = 300005;
const ll inf = 2e18;

#define ptr nodo*
#define tam 301000
ll n,m,v,p;
ll  valor[tam],arr[tam];
bool f(int pos0)
{
    forr(i,0,n)
    arr[i]=valor[i];
    arr[pos0]+=m;
    ll avalor=arr[pos0];
    if (arr[pos0]<arr[p-1])
        return 0;
    ll tot= n-pos0;
    sort(arr,arr+pos0+1);
    reverse(arr,arr+pos0+1);
    
    /*int cnt=0,ant=-1;
    forr(i,0,pos0+1)
    {
        if (ant==arr[i])
            cnt++;
        else
        {
            if (cnt>=p)break;
            cnt++;
            ant=arr[i];
        }
    }*/
    tot+=p-1;
    ll atot=0;
    
    forr(i,p,pos0+1)
    {
        //<<arr[i]<<' ';
        atot+=(avalor-arr[i]);
    }
    tot+=(atot/m);
    
    return (tot>=v);
}
int main () 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin>>n>>m>>v>>p;
    
    forr(i,0,n)
    {
        cin>>valor[i];
    }
    sort(valor,valor+n);
    reverse(valor,valor+n);    
    int cnt,iz,ant=-1;
    cnt=0;
    forr(i,0,n)
    {
        

        iz=i;
        if (ant==valor[i])
            cnt++;
        else
        {
            if (cnt>=p)break;
            ant=valor[i];
            cnt++;
        }
    }
    
    int der,mid;
    der=n;
    while(iz+1<der)
    {
        mid=(iz+der)/2;
        if (f(mid))
            iz=mid;
        else
            der=mid;
    }
    
    if (f(iz)==0)
        iz=iz-1;

    cout<<iz+1<<endl;
}
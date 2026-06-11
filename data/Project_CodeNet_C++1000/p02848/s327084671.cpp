/**
 *   Author:  Wasi Ur Rahman
 *   FROM RMSTU
**/
#include <bits/stdc++.h>
#define ll                      long long
#define boost                   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ticktock                cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n"
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(d,min3(a,b,c))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(d,max3(a,b,c))
#define all(v)                  v.begin(),v.end()
#define revall(v)               v.rbegin(),v.rend()
#define pb                      push_back
#define Max(v)                  *max_element(all(v))
#define Min(v)                  *min_element(all(v))
#define eb                      emplace_back
#define vll                     vector<ll>
#define sci(t)                  scanf("%d",&t)
#define scl(t)                  scanf("%lld",&t)
#define memset(a, b)            memset(a, (b), sizeof(a))
#define setbits(x)              __builtin_popcountll(x)
#define zrobits(x)              __builtin_ctzll(x)
#define si(x)                   scanf("%d", &x)
#define sii(x, y)               scanf("%d %d", &x, &y)
#define siii(x, y, z)           scanf("%d %d %d", &x, &y, &z)
#define siiii(p,x, y, z)        scanf("%d %d %d %d",&p, &x, &y, &z)
#define sl(x)                   scanf("%lld", &x)
#define sll(x, y)               scanf("%lld %lld", &x, &y)
#define slll(x, y, z)           scanf("%lld %lld %lld", &x, &y, &z)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define println()               cout << endl
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define printi(x)               printf("%d\n")
#define printii(x,y)            printf("%d %d\n")
#define printiii(x,y,z)         printf("%d %d %d\n")
#define printl(x)               printf("%lld\n")
#define printll(x,y)            printf("%lld %lld\n")
#define printlll(x,y,z)         printf("%lld %lld %lld\n")
#define chkbit(x,p)             ((x&(1LL<<p))?1:0)
#define setbit(x,p)             x|=(1LL<<p)
#define clrbit(x,p)             x=x&(~(1LL<<p))
#define revbit(x,p)             (chkbit(x,p)?clrbit(x,p):setbit(x,p))
using namespace std;
int main(){
    boost;
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = s.size();
    int p;
    cin >> p;
    string str;
    cin >> str;
    string a = "";
    for(int i = 0;i<str.size();i++)
    {
        a += str[i];
        int t = s.find(a);
        str[i] = s[(t+p)%n];
        a.clear();
    }
    cout << str << endl;
}

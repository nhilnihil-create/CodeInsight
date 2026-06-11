#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define sd(x)   scanf("%g",&x)
#define ss(s)	scanf("%s",s)
#define pd(x)   printf("%g\n",x)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define nline   printf("\n")
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define fitr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
void update(multiset<int> &best, int c[],int pos,int val);
int main()
{
    int r,c,n,i;
    si(r);si(c);si(n);
    int cols[c];
    multiset<int> best;
    vector<int> row[r];
    fo(i,c)
    {
        cols[i] = 0;
        best.insert(0);
    }
    fo(i,n)
    {
        int x,y;
        si(x);si(y);
        x--;y--;
        row[x].pb(y);
        update(best,cols,y,1);
    }
    int res = 0;
    fo(i,r)
    {
        int bmbs = row[i].size();
        for(int x:row[i])
        {
            update(best,cols,x,-1);
        }
        if(best.size())
        bmbs+=*best.rbegin();
        res = max(res,bmbs);
        for(int x:row[i])
        {
            update(best,cols,x,1);
        }
    }
    pi(res);
}
void update(multiset<int> &best, int c[],int pos,int val)
{
    best.erase(best.find(c[pos]));
    c[pos]+=val;
    best.insert(c[pos]);
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const int mx=1e6+11;
const double PI = acos(-1);
#define MOD 1000000007


#define nl '\n'
#define pb push_back
#define F first
#define S second
#define I insert
#define mp make_pair

#define sz(x) x.size()
#define tt int t; cin>>t; while(t--)
#define lo(i,a,b) for(int i=a;i<b;i++)
#define rlo(i,n) for(int i=n-1;i>=0;i--)
#define be(a) (a).begin(),(a).end()
#define rbe(a) (a).rbegin(),(a).rend()
#define mem(a,b) memset(a,b,sizeof(a))
#define pr(a) {for(auto x:a)cout<<x<<" ";cout<<nl;}
#define yes cout<<"Yes"<<nl
#define no cout<<"No"<<nl
#define su ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define frac cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu ()
{
    cerr << endl;
}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest)
{
    cerr << arg << ' ';
    faltu(rest...);
}

bool row(int a[][3])
{
    if(a[0][1]==0&&a[0][1]==a[0][2]&&a[0][2]==a[0][0])
        return true;
    if(a[1][1]==0&&a[1][1]==a[1][2]&&a[1][2]==a[1][0])
        return true;
    if(a[2][1]==0&&a[2][1]==a[2][2]&&a[2][2]==a[2][0])
        return true;
    return false;
}

bool col(int a[][3])
{
    if(a[0][0]==0&&a[0][0]==a[1][0]&&a[1][0]==a[2][0])
        return true;
    if(a[0][1]==0&&a[0][1]==a[1][1]&&a[1][1]==a[2][1])
        return true;
    if(a[0][2]==0&&a[0][2]==a[1][2]&&a[1][2]==a[2][2])
        return true;
    return false;
}

bool dia1(int a[][3])
{
  if(a[0][0]==0&&a[0][0]==a[1][1]&&a[1][1]==a[2][2])
    return true;
  else
    return false;
}

bool dia2(int a[][3])
{
  if(a[1][1]==0&&a[0][2]==a[1][1]&&a[1][1]==a[2][0])
    return true;
  else
    return false;
}

void f()
{
    int a[3][3],q;
    map<int,int>m;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>a[i][j];
        }
    }

    tt
    {
        cin>>q;
        m[q]++;
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(m[a[i][j]]>0)
            {
                a[i][j]=0;
            }
        }
    }
    if(row(a)==true)
        yes;
    else if(col(a)==true)
        yes;
    else if(dia1(a)==true)
        yes;
    else if(dia2(a)==true)
        yes;
    else
        no;
}

int main()
{
    su;
    f();
    return 0;
}

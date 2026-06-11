#include<bits/stdc++.h>

#define nl                 "\n"
#define ll                 long long
#define pb                 push_back
#define pf                 push_front
#define np                 next_permutation
#define pp                 prev_permutation
#define sqr(x)             ((x)*(x))
#define pi                 acos(-1)
#define setprecision(x)    fixed<<setprecision((int)(x))
#define mem1(x)            memset(x,0,sizeof(x))
#define mem2(x)            memset(x,-1,sizeof(x))
#define all(x)             (x).begin(),(x).end()
#define sort1(x)           sort(all(x))
#define csort(x,c)         sort(all(x),c)
#define rsort(x)           sort(x.rbegin(),x.rend())
#define rep(i,n,m)         for(int i=(int)(n); i<(int)(m); i++)

//typedef map<int,int> mapii;
//typedef map<string,int> mapsi;
//typedef map<int,string> mapis;
//typedef vector<int> vi;
//typedef vector<vectori> v2d;
//typedef vector<long long> vll;


using namespace std;
void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int i=0,j=n-1,sum1=0,sum2=0;
    while(i<=j)
    {
        if(sum1<=sum2)
        {
            sum1+=a[i];
            i++;
        }
        else
        {
            sum2+=a[j];
            j--;
        }
    }
    cout<<abs(sum1-sum2)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int t; cin>>t; while(t--){solve();}
    solve();
    return 0;
}

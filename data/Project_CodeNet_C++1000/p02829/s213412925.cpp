#include<bits/stdc++.h>
using namespace std;
/******************************TYPE name************************************/
typedef long long ll;
typedef vector<int> vi;
typedef pair<int ,int > pii;
typedef map<int,int>mii;

/***********************************MACRO*************************/
#define test int ct;cin>>ct;while(ct--)
#define fo(i,n) for( i=0;i<n;i++)
#define el <<"\n"
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define sq(a) (a)*(a)
#define file() freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define zro 1e-9
#define F first
#define S second
#define pb(a) push_back(a)
#define sqsum(n) (((n)*(n+1)*(2*(n)+1))/6) //sum of square number 1 to n
#define mltpls(first,last,ratio) ((last)*(ratio)-(first))/(ratio-1) //multiple series
#define linear_sum(n) (n)*(n+1)/2; //sum of 1 to n
#define arithmetic_progression(first,last,ratio) ((ratio)*(first+last))/2
#define rb rbegin()
#define re rend()
#define bg begin()
#define en end()
#define itr iterator
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int i;
#define gcd(a,b) __gcd(a,b)
#define gl(s) getline(cin,s)

//code: amr and music :: map of vector

/********************************code***************************/
int main()
{
    int a[3]={0};
    fo(i,2)
    {
        int k;
        cin>>k;
        a[k-1]=1;
    }
    fo(i,3)
    {
        if(a[i]==0)
            cout<<(i+1);
    }
}

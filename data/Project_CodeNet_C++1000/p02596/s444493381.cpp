#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#define l(i,a,b) for(auto i=a;i<b;i++)
#define lr(i,a,b) for(auto i=a;i>=b;i--)
#define ll long long
#define lli long long int
#define ld long double
#define vec vector<int>
#define mii map<ll,ll>
#define vl vector<long long>
#define se set <long long int>
#define pi pair<long long,long long>
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define in(x) cin>>x
#define o(x) cout<<x
#define SYNC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI 3.14159265359
using namespace std;


//const string k = "enterstringtobechecked";

const int K = 1e6 + 10;
bool seen[K];

int main()
{
    SYNC
   // clock_t tStart = clock();
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    ll n; in(n);
    ll count=0;
    ll k=7%n;
    while(!seen[k])
    {
        seen[k]=true;
        count++;
        if(k==0)
        {
            o(count)<<endl;
            return 0;
        }
        k=((k*10)+7)%n;
    }
    o(-1)<<endl;






    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);   
}

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();

int n;
cin>> n;

ll b[n+1], sum= 0;

for(int i= 0; i<n-1; i++)
{
    cin>> b[i];

    sum+= (i ==0? b[i] : min( b[i], b[i-1]));

}

sum += b[n-2];
cout<< sum ;
nl;

    return 0;
}



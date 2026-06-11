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

    int a[3], k;

    cin>> a[0]>> a[1]>> a[2]>> k;

    int i=0, sum=0;
    while(k!=0)
    {
        if(i==2)
            sum-= min(k, a[i]);
        else if(i== 0)
            sum+= min(k, a[i]);

        k-=(min(k, a[i]));
           i++;
    }

    cout<< sum;
    nl;


    return 0;
}



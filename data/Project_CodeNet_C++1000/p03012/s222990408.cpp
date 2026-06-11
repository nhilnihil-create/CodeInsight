#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int tc; cin>>tc; while(tc--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();


    int n, s1= 0, s2=0;
    cin>> n;
    int a[n];

    for(int i=0; i<n; i++)
        cin>> a[i];


    for(int i=n-1, j=0; i>=j; )
    {
        if( s1< s2)
        {
            s1+= a[i];
            i--;
        }
        else
        {
            s2+= a[j];
            j++;
        }

    }



    cout << abs( s2-s1);

    return 0;
}

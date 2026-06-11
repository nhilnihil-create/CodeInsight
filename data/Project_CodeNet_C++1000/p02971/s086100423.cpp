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

    int a[n];

    for(int i=0; i<n; i++)
        cin>> a[i];

        int *mx= max_element (a, a+n);
        int d= distance (a, mx);

        sort(a, a+n);


    for(int i=0; i<n; i++)
       {
           if(i== d)
            cout << a[n-2];
           else
            cout<< a[n-1];
           nl;
       }
    return 0;
}



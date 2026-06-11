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


    int a[4][4];

    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
            cin >> a[i][j];
    }

    int n;

    cin>> n;

    int t, k;

    for(int i=0; i<n; i++)
    {
        cin>> t;

        for(int j=1; j<= 3; j++)
        {
            for( k=1; k<=3; k++)
            {
                if(t== a[j][k])
                {
                    a[j][k]= -1;
                    break;
                }
            }
            if(a[j][k] == -1)
                break;
        }
    }

    if ( (a[1][1] == -1 && a[2][2]== -1 &&  a[3][3]== -1) || (a[1][3]== -1 && a[2][2]== -1 && a[3][1]== -1) )
    {
        cout<< "Yes\n";
        return 0;
    }

    for(int i=1; i<=3; i++)
    {
        if( (a[i][1] ==a[i][2] && a[i][3] == a[i][2]) || ((a[1][i] ==a[2][i] && a[3][i] == a[2][i])) )
        {
            cout<< "Yes\n";
            return 0;

        }
    }

    cout<< "No\n";

    return 0;
}



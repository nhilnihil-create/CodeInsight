#include <bits/stdc++.h>
using namespace std;


//defines...
#define ll long long
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define in insert
#define pi 2*acos(0.0)1
#define srt(s) sort(s.begin(),s.end())
#define all(x) x.begin(),x.end()

const ll mod=1e9+7;
const ll MX=2e5+5;

//code goes from here...



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif

    boost
    //---------------------------------
    int ar[3][3];
    for(int i=0;i<3 ;i++)
    {
        for(int j=0;j < 3; j++)
        {
            cin >> ar[i][j];
        }
    }
    int n;
    cin >> n;
    for(int k=0; k< n ;k++)
    {
        int x; 
        cin >> x ;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(ar[i][j]==x) ar[i][j]=-1;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        if(ar[i][0]==-1 && ar[i][1]==-1 && ar[i][2]==-1) return cout << "Yes\n",0;
        if(ar[0][i]==-1 && ar[1][i]==-1 && ar[2][i]==-1) return cout << "Yes\n",0;
    }
    if(ar[0][0]==-1 && ar[1][1]==-1 && ar[2][2]==-1) return cout << "Yes\n",0;
    if(ar[0][2]==-1 && ar[1][1]==-1 && ar[2][0]==-1) return cout << "Yes\n",0;
    cout << "No\n";
    //---------------------------------
    
    return 0;
}

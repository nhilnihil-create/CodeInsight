/*----------------------|
/ Author : Ashraf Tasin |
/ Date   :   08.08.19   |
/----------------------*/

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define all v.begin(),v.end()
#define flash ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define db double
#define endl "\n"
#define mnm pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>
#define show for(int i=0;i<v.size();i++) cout << v[i] << " ";
#define eps 1e-6
#define mx 100008
#define mod 1000000007
using namespace std;

/*King Moves
int dx[]={-1,1,-1,0,1,-1,0,1};
int dy[]={0,0,-1,-1,-1,1,1,1}; */

/*Knight Moves

int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 }; */

/*Normal Moves

int x[] = {0, 1, 0, -1};
int y[] = {-1, 0, 1, 0}; */

int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    flash

    int n,k;
    cin >> n >> k;

    if(k==1) return(cout << 0 << endl,0);
    else cout << (n-k+1)-1 << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s[2005];
int r,c;
int mat[2005][2005][4];
int row[]= {1,0,-1,0,1,-1,1,-1};
int colm[]= {0,1,0,-1,1,-1,-1,1};

int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>r>>c;
    for(int i=0; i<r; i++)
        cin>>s[i];
    for(int i=0; i<r; i++)
    {
        int cnt=0;
        for(int j=0; j<c; j++)
        {
            if(s[i][j]=='.')
                cnt++;
            else
                cnt=0;
            mat[i][j][0]=cnt;
        }
        cnt=0;
        for(int j=c-1; j>=0; j--)
        {
            if(s[i][j]=='.')
                cnt++;
            else
                cnt=0;
            mat[i][j][1]=cnt;
        }
    }
    for(int i=0; i<c; i++)
    {
        int cnt=0;
        for(int j=0; j<r; j++)
        {

            if(s[j][i]=='.')
                cnt++;
            else
                cnt=0;
            mat[j][i][2]=cnt;
        }
        cnt=0;
        for(int j=r-1; j>=0; j--)
        {

            if(s[j][i]=='.')
                cnt++;
            else
                cnt=0;
            mat[j][i][3]=cnt;
        }
    }
    int mx=0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(s[i][j]=='.')
            {
                int ans=0;
                for(int k=0; k<4; k++)
                    ans+=mat[i][j][k];
                ans-=3;
                mx=max(ans,mx);
            }
        }
    }
    cout<<mx<<endl;



    return 0;
}

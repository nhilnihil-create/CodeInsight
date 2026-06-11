#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    vector<vector<int>> a(3,vector<int> (3)),data(3,vector<int> (3));
    rep(i,3) rep(k,3) cin>>a[i][k];
    int n,ans=0;
    cin>>n;
    rep(j,n)
    {
        int b;
        cin>>b;
        rep(i,3) rep(k,3)
        {
            if(a[i][k]==b)
            {
                data[i][k]=1;
                break;
            }
        }
    }
    if(data[0][0]==1&&data[0][1]==1&&data[0][2]==1) ans++;
    if(data[1][0]==1&&data[1][1]==1&&data[1][2]==1) ans++;
    if(data[2][0]==1&&data[2][1]==1&&data[2][2]==1) ans++;
    if(data[0][0]==1&&data[1][0]==1&&data[2][0]==1) ans++;
    if(data[0][1]==1&&data[1][1]==1&&data[2][1]==1) ans++;
    if(data[0][2]==1&&data[1][2]==1&&data[2][2]==1) ans++;
    if(data[0][0]==1&&data[1][1]==1&&data[2][2]==1) ans++;
    if(data[0][2]==1&&data[1][1]==1&&data[2][0]==1) ans++;
    if(ans>0)cout<<"Yes";
    else cout<<"No";
}
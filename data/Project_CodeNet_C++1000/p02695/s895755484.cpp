/*
                                             ::                     ::
                                             ':                     :
                                              :.                    :
                                           ;' ::                   ::  '
                                          .'  ';                   ;'  '.
                                         ::    :;                 ;:    ::
                                         ;      :;.             ,;:     ::
                                         :;      :;:           ,;"      ::
                                         ::.      ':;  ..,.;  ;:'     ,.;:
                                          "'"...   '::,::::: ;:   .;.;""'
                                              '"""....;:::::;,;.;"""
                                          .:::.....'"':::::::'",...;::::;.
                                         ;:' '""'"";.,;:::::;.'""""""  ':;
                                        ::'         ;::;:::;::..         :;
                                       ::         ,;:::::::::::;:..       ::
                                       ;'     ,;;:;::::::::::::::;";..    ':.
                                      ::     ;:"  ::::::"""'::::::  ":     ::
                                       :.    ::   ::::::;  :::::::   :     ;
                                        ;    ::   :::::::  :::::::   :    ;
                                         '   ::   ::::::....:::::'  ,:   '
                                          '  ::    :::::::::::::"   ::
                                             ::     ':::::::::"'    ::
                                             ':       """""""'      ::
                                              ::                   ;:
                                              ':;                 ;:"


                                                     P_r_A_d_Y
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define mod 1000000007
#define inf 1e18
const int N = 300005;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
void cs(int &x)
{
    cout << "Case #" << x << ": ";
}
bool cmp(string a, string b)
{
    return a + b < b + a;
}
int n,m,q,ans=0;
vector<vector<int>>qw;
vector<int>v;
void help(int i,int val)
{
    if(i==n)
    {
        int cnt=0;
        for(int j=0;j<q;j++)
        {
            if(v[qw[j][1]-1]-v[qw[j][0]-1]== qw[j][2])
                cnt+=qw[j][3];
        }

        ans=max(ans,cnt);
        return ;
    }


    for(int p=val;p<=m;p++)
    {
        v[i]=p;
        help(i+1,p);
    }


}
int32_t main()
{
    fastIO;
    // int t; cin >> t;
    // int x = 1;
    // while (t--)
    // {

        cin>>n>>m>>q;
        qw.resize(q,vector<int>(4));
        v.resize(n);

        for(int i=0;i<q;i++)
        {
            cin>>qw[i][0]>>qw[i][1]>>qw[i][2]>>qw[i][3];
        }

        help(0,1);
        cout<<ans<<endl;

    //}
    return 0;
}

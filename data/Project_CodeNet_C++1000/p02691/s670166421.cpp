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

int32_t main()
{
    fastIO;
    // int t; cin >> t;
    // int x = 1;
    // while (t--)
    // {

    int n;cin>>n;
    vector<int>h(n);

    for(int i=0;i<n;i++)
        cin>>h[i];

    map<int,vector<int>>m;

    for(int i=0;i<n;i++)
    {
        m[h[i]+i].push_back(i);
    }

    int c=0;

    for(int i=n-1;i>=0;i--)
    {
        int r=i-h[i];
        if(r<=0)
            continue;

        c+= upper_bound(m[r].begin(),m[r].end(),i-1)-m[r].begin();

    }

    cout<<c<<endl;



    //}
    return 0;
}
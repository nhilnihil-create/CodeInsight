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
        vector<int>m(n+1,0);
        for(int i=0;i<n-1;i++)
        {
            int x;cin>>x;
            m[x]++;
        }

        for(int i=1;i<=n;i++)
            cout<<m[i]<<endl;
        



    // }
    return 0;
}

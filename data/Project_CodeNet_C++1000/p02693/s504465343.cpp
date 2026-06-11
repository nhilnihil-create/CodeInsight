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

        int k,a,b;cin>>k>>a>>b;
        int r=a%k;
        if(r==0 || b%k==0)
            cout<<"OK"<<endl;
        else
        {
            if(a/k<b/k)
                cout<<"OK"<<endl;
            else
                cout<<"NG"<<endl;
        }
    //}
    return 0;
}
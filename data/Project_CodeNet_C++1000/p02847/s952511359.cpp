/*
    Author : Ritesh Singh
*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
using namespace __gnu_pbds; 
using namespace std;
#define lct long long int t;cin>>t;while(t--)
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,n) for (int i=a;i<n;i++)
#define el '\n'
#define IOS ios_base::sync_with_stdio(false), cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;

typedef tree<string, null_type, less<string>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set; 
 
int32_t main()
{
    IOS;
    string s; cin>>s;
    if(s=="SUN") cout<<7;
    else if(s=="MON") cout<<6;
    else if(s=="TUE") cout<<5;
    else if(s=="WED") cout<<4;
    else if(s=="THU") cout<<3;
    else if(s=="FRI") cout<<2;
    else if(s=="SAT") cout<<1;
}


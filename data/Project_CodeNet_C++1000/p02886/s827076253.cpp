#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define llu unsigned long long
#define U unsigned int
#define ff first
#define ss second
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pair pair<ll,ll>
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 10000
vector<ll>vec;
map<string,ll> mps;
map<ll,string> mpss;
set<ll>s1;
set<string>s2;
map<string,ll>::iterator str;
set<ll>::iterator itr;
/*
std::cout << std::fixed;
std::cout << std::setprecision(1);
std::cout << VALUE NAME<<endl;
*/
ll tra[100006],tra1[100006];


int main()
{
    fast_cin;
    ll t;

        map<ll,ll>mp;
        map<ll,ll>::iterator it;
        string s,s1;
        ll lock=0,sum=0,co=0;
        ll n,m;
        cin>>n;

        ll str[n+5];
        for(int i=0;i<n;i++)
            cin>>str[i];

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i!=j)
                {
                    sum+=str[i]*str[j];
                }
            }
        }

         cout<<sum<<endl;

        s1.clear();
        vec.clear();

}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;

const int N=1e7;

ll v[N+10];

ll a[N+10];


bool compare(string  &a, string &b)
{
     string f=a+b,c=b+a;

     return f<c;
}

int main()
{
    ll a;

    string str;

    cin>>a>>str;

   if(a<3200)cout<<"red"<<endl;

   else cout<<str<<endl;

}







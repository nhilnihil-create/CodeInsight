#include<bits/stdc++.h>
using namespace std;
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
//define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const long long int infLL = 9000000000000000000;
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(a) (a).begin(),(a).end()
#define mx_int_prime 999999937
const int inf = 2000000000;
const double PI = acos(-1);
const double eps = 1e-9;
typedef long double ld;
#define MOD 1000000007
typedef long long ll;
const int mx=2e5+125;
//ll p[mx],a[mx],b[mx];
#define PB push_back
#define endl '\n'
#define S second
#define F first
int main()
{
    faster();
    string s;
    string ans;
    cin>>s;
    int len=s.size();
    ans=s;
    reverse(all(ans));
    int c=0;
    if(s==ans)c++;
    int n=((len-1)/2);
    string ck,ck1;
    ck="";
    for(int i=0; i<n; i++)
        ck+=s[i];
    ck1=ck;
    reverse(all(ck1));
    if(ck1==ck)c++;
    string cmp,cmp1;
    cmp="";
    int m=(len+3)/2;
    for(int i=m-1; i<len; i++)
        cmp+=s[i];
    cmp1=cmp;
    reverse(all(cmp1));
    if(cmp1==cmp)c++;
    if(c==3)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


    return  0;
}

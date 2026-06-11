#include<bits/stdc++.h>
using namespace std;
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
ll p[mx],a[mx],b[mx];
#define PB push_back
//#define '\n' endl
#define S second
#define F first
int main()
{
    faster();
    char a,b;
    cin>>a>>b;
    int len1,len2;
    len1=a-'0';
    len2=b-'0';
    string s1,s2;
    s1="",s2="";
    for(int i=0; i<len2; i++)
        s1+=a;
    for(int i=0; i<len1; i++)
        s2+=b;
    if(s1>=s2)
        cout<<s2<<endl;
    else
        cout<<s1<<endl;


    return  0;
}

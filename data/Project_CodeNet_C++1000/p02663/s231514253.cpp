
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sc(n) int n; scanf("%d",&n);
#define mod 10000007
#define N 100001
#define MX 1000000001
#define log(n) (int)log2(n)
#define logg(a)(b) log(b)/log(a)
#define pb(x) push_back(x);
#define T int t, q=0; scanf("%d", &t); while(q++<t)
#define pi acos(-1)
#define flag bool fl=true;
#define fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);

int main()
{

        ll h1, m1, h2, m2, k,tot=0;
        cin>>h1>>m1>>h2>>m2>>k;
        h1=h1*60;
        h2=h2*60;

        tot=abs(-h1+h2-m1+m2);
        cout<<tot-k<<endl;


}


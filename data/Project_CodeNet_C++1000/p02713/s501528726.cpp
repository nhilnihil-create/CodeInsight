
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main()
{

ll k ;
cin>>k;

ll ans =0;
for(int a = 1 ; a <=k;a++)
    for(int b = 1 ; b<=k ; b++)
    for(int c = 1 ; c<= k ; c++)
    ans += __gcd(a,__gcd(b,c));





cout<<ans<<endl;


 return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pb push_back
#define mp make_pair
#define fi(i,start,end) for(int i=start; i < end ; ++i)
#define Fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
//#define mod 100000000

using namespace std;



int main()
{
    //cout<<26*26*26+702;
    long long unsigned int n;
    cin>>n;
    string ans="";
    while(n)
    {

        n--;
        ans+= char('a'+ n%26 );
        n=n/26;
    }
    reverse(ans.begin(),ans.end());

    cout<<ans<<endl;

}








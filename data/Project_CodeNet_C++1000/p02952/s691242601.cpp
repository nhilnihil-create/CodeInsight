#include<bits/stdc++.h>
#define lld long long int
#define vec vector<lld>
#define pll pair<lld,lld>
#define pb push_back
#define ss second
#define ff first
#define mp make_pair
#define mod 1000000007
#define answer cout<<endl<<"answer : ";
#define maxn 100005
#define messi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
lld fuck(lld x)
{
    lld cnt=0;
    while(x>0)
    {
        x=x/10;
        cnt++;
    }
    return cnt;
}
int main() {messi lld t=1;//cin>>t;
    while(t--)
    {
        lld n=0,m=0,k=0,i=0,j=0,p=0,q=0,x=0,y=0,z=0,ans=0,cnt=0;string s;bool flag=false;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            x=fuck(i);
            if(x%2==1)
                ans++;
        }
        cout<<ans<<endl;

    }
	return 0;
}
/*  CODED BY:-
 ________________________________________
|            __        __                |
|  /\   /\  |__)  /\  |  \ |__| \ /  /\  |
| /~~\ /~~\ |  \ /~~\ |__/ |  |  |  /~~\ |
|________________________________________|

*/

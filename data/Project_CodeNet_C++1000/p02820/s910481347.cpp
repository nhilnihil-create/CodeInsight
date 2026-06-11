#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
int r,s,p;

int judge(char player,char m)
{
    if(player=='r'&&m=='s') return r;
    else if(player=='s'&&m=='p') return s;
    else if(player=='p'&&m=='r') return p;
    else return 0;
    
}

int main(void)
{
    int ans =0;
    int n,k;
    cin>>n>>k;

    cin>>r>>s>>p;

    string s;
    cin>>s;

    for(int i=0;i<k;i++)    // sub DP i(0~K)
    {

        int rjp = 0;
        int sjp = 0;
        int pjp = 0;

        for(int j=i;j<n;j+=k)
        {
            //　j番目にr,s,pを出すときの最大値
            int rj=judge('r',s[j]) +max(sjp,pjp);
            int sj=judge('s',s[j]) +max(rjp,pjp);
            int pj=judge('p',s[j]) +max(sjp,rjp);

            rjp= rj;
            sjp=sj;
            pjp=pj;
        }


        ans += max(rjp,max(sjp,pjp));
    }
    cout<<ans<<endl;

}
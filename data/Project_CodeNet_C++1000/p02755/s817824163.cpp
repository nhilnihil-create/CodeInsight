#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main()
{
   IOS;
   //freopen("inputfile.txt","r",stdin);
 double a,b;cin>>a>>b;
 double ma1 = 10000.0;
 double ma2 = 10000.0;
 double ans1 = (a)/(0.08);
 //cout<<ans1<<endl;
 if(floor(ans1*(0.1))== b)ma1 = ans1;
 double ans2 = b/(0.1);
 if(floor(ans2*(0.08))==a)ma2 = ans2;
 if(min(ma1,ma2)==10000.0)cout<<"-1"<<endl;
 else cout<<ceil(min(ma1,ma2))<<endl;
    return 0;
}
//<!...........ALHAMDULILLAH.............!!>>

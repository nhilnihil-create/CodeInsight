#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define debug(x) cout << #x << " : " << x << endl
#define mp make_pair
#include <iostream>
#define fastinput ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int main()
{    
    fastinput;
    LL n,i,j,k,t,temp,a,b;
    cin>>n>>a>>b;
    LL diff=a-b;
    if((a-b)%2==0)
    {
        cout<<((b-a)/2)<<endl;
    }
    else
    {
        //option 1
        LL t1=a;
        LL pos_b=b-t1-1;//even
        LL ans1=t1+(pos_b/2);

        //option 2
        LL t2=n-b+1;
        LL pos_a=a+t2;
        LL ans2=t2+(n-(pos_a))/2;
        //debug(ans1);
        //debug(ans2);
        cout<<min(ans1,ans2)<<endl;
    }
    
    
    


    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb  push_back
int32_t main()
{
     string S;
     cin>>S;
     if(S=="RRR")
     cout<<3;
     else if((S=="RRS") || (S=="SRR"))
     cout<<2;
     else if ((S=="RSS") || (S=="SSR") || (S=="SRS") || (S=="RSR"))
     cout<<1;
     else
     cout<<0;

     return 0;
    

}

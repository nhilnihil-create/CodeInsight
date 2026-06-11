//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;
int main()
{
    ll a,b,i,ans[3]={0};
    cin>>a>>b;
    ans[a-1]=1;
    ans[b-1]=1;
    for(i=0;i<3;i++)
    if(ans[i]==0){
        cout<<i+1<<endl;
    }






    return 0;
}




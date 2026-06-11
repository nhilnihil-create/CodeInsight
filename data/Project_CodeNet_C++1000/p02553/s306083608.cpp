#include<iostream>
using namespace std;
int main()
{
    long a,b,c,d;
    long long int ans1,ans2,ans3,ans4,ans;
    cin>>a>>b>>c>>d;
    ans1=a*c;
    ans2=a*d;
    ans3=b*c;
    ans4=b*d;
    ans=max(ans1,ans2);
    ans=max(ans,ans3);
    ans=max(ans,ans4);
    cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a, b, c, d, ans, temp1, temp2, temp3, temp4;
    cin>>a>>b>>c>>d;
    temp1=a*c;
    temp2=a*d;
    temp3=b*c;
    temp4=b*d;
    ans=max(temp1, max(temp2, max(temp3, temp4)));
    cout<<ans<<endl;

}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long N,A,B,ans=0;
    cin>>N>>A>>B;
    long long div=N/(A+B);
    long long Mod=N%(A+B);
    ans+=(div*A);
    ans+=min(Mod,A);
    cout<<ans<<endl;
}

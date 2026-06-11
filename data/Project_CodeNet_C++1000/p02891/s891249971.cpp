#include <bits/stdc++.h>
using namespace std;
string s;
long long k;
long long a[10];
int main()
{
    cin>>s;
    scanf("%lld",&k);
    string tmp=s+s+s;
    for(int i=1;i<tmp.size();i++){
        if(tmp[i]==tmp[i-1]){
            tmp[i]='.';
            a[(i/s.size())]++;
        }
    }
    k--;
    long long ans=a[0];
    ans+=(k+1)/2*a[1];
    ans+=k/2*a[2];
    printf("%lld",ans);
    return 0;
}

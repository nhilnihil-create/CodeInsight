#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long k;cin>>k;

    queue<long long> q;
    for(long long i=1;i<=9;i++)
        q.push(i);

    long long ans;
    while(k--){
        ans=q.front();
        q.pop();

        long long m=ans%10;
        
        if(m>0) q.push(ans*10+m-1);
        q.push(ans*10+m);
        if(m<9) q.push(ans*10+m+1);
    }
    cout<<ans;
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,cnt=1,j=0;
    cin>>a;
    while(a>=1){
        cnt*=2;
        j+=cnt;
        a/=2;
    }
    cout<<cnt-1;
}

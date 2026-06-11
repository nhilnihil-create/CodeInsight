#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int n,sum=0;
    cin>>n;

    for(long int i=1;i<=n;i++){
        if(i%3!=0 && i%5!=0){
            sum+=i;
        }
    }
    cout<<sum<<"\n";

    return 0;
}

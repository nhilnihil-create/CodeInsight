#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    long long int sum=0;
    cin>>k;

    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                sum+=__gcd(__gcd(i,j),l);
            }
        }
    }
    cout<<sum<<"\n";

    return 0;
}

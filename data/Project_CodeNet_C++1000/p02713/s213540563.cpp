#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, R=0;
    cin>>K;
    for(int I = 1; I<=K; I++)
    {
        for(int J = 1; J<=K; J++)
        {
            for(int L = 1; L<=K; L++)
            {
                R+=__gcd(I, __gcd(J, L));
            }
        }
    }
    cout<<R<<endl;
    return 0;
}

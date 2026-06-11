#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bitset<100010> prime;
const int ub = 100003;

void sieve()
{
    prime.set();
    prime[0] = prime[1] = 0;

    for(int I = 4; I<=ub; I+=2)
    {
        prime[I] = 0;
    }

    for(int I = 3; I*I<=ub; I+=2)
    {
        if(prime[I])
        {
            for(int J = I*I; J<=ub; J+=I)
            {
                prime[J] = 0;
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    int N;
    cin>>N;
    while(!prime[N])N++;
    cout<<N<<endl;
    return 0;
}

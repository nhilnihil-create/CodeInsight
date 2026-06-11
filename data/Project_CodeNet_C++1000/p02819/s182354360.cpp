//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll n=110000,k,i,j;
    cin>>k;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    for(j=k;; j++)
    {
        if(prime[j])
        {

            cout<<j<<endl;
            break;
        }
    }

    return 0;
}




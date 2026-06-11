#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll N, i, ans, temp;
int main()
{
    cin >> N;
    i = 2;
    while(i*i<=N)
    {
        temp = i;
        if(N%temp==0)
        {
            while(N%temp==0)
            {
                N /= temp;
                temp = temp*i;
                ans++;
            }
            while(N%i==0)
                N/=i;
        }
        i++;
    }
    if(N>1)
        ans++;
    cout << ans;
}

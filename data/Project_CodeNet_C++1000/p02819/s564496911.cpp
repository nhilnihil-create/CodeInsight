#include<bits/stdc++.h>
using namespace std;

bool marked[(int)1e6];
void sieve()
{
    memset(marked, true, sizeof(marked));
    for(long long i = 2; i * i < (int)1e6; i++)
    {
        if(marked[i] == true)
        {
            for(long long j = i * i; j < (int)1e6; j += i)
            {
                marked[j] = false;
            }
        }
    }
}

int main()
{
    sieve();
    int x;
    cin >> x;
    while(marked[x] == false)
        x++;
    cout << x << endl;
}

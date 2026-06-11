#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,M;
    cin >> N >> M;
    if(M>0)
    {
        cout << (2*M+N)*(N-1)/2 << endl;
    }
    else
    {
        bool chk=true;
        int sum=0;
        for(int i=M; i<N+M; i++)
        {
            sum+=i;
            if(i==0)
            {
                chk=false;
            }
        }
        if(chk)
        cout << sum-(N+M-1) << endl;
        else
        cout << sum << endl;
    }
    
}
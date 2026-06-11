#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, counT = 0;
    cin >> N;

    char str[N];
    scanf("%s", &str);

    for(int i=0; i<N-2; i++)
    {
        if(str[i]=='A' && str[i+1]=='B' && str[i+2]=='C')
        {
            counT++;
            i += 2;
        }
    }

    cout << counT;

    return 0;
}
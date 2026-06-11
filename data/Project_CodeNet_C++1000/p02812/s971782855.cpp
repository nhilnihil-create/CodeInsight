#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,i,j=0;

    char A[51];

    cin>> a;
    
    getchar();
    
    cin>> A;

    for(i=0;i<a-2;i++)
    {
        if(A[i]=='A')
        {
            if(A[i+1] == 'B' && A[i+2] == 'C')
            {
                j++;
            }
        }
    }

    cout<< j<< endl;

    return 0;
}
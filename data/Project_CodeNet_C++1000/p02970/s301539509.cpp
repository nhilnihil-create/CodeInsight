#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,A;
    cin >> N >> A;
    int B=A*2+1;
    if(N%B==0)
    {
        cout << N/B <<endl;
    }
    else
    {
        cout << N/B+1 <<endl;
    }
    
}
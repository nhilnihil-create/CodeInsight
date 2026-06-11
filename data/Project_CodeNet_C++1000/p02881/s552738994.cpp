#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int N, rt, mi, i;
    cin >> N;
    mi=N;
    rt=sqrt(N);
    for(i=1;i<=rt;i++) {
        if(!(N%i)) {
           mi=min(mi,((i-1)+((N/i)-1)));
        }
    }
    cout << mi << endl;
    return 0;
}
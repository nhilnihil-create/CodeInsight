#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int N;
    cin>>N;
    vector<int> A(N);
    int sum=0;
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
        sum^=A[i];
    }
    for(int i=0;i<N;i++)cout<<(A[i]^sum)<<endl;
}
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main() 
{
    constexpr int kinf=100001;
    int N,K;
    cin>>N;

    vector<int>B;
    for (int i = 0; i < N-1; i++)
    {
        int b;
        cin>>b;
        B.push_back(b);
    }
    B.push_back(kinf);

    vector<int>A(N);
    A[0]=B[0];

    for (int i = 1; i < N; i++)
    {
        A[i]=min(B[i-1],B[i]);
    }

    int ans =accumulate(A.begin(),A.end(),0);
    cout<<ans<<endl;
    return 0;
}
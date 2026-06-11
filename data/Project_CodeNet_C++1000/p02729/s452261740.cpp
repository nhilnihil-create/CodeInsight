#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M,N;
    cin>>N>>M;
    if(N>=0&&M>=0&&N<=100&&M<=100&&(M+N)>=2){
    int sum=((N*(N-1))/2) +((M*(M-1))/2);
    cout<<sum;
    }
   return 0;
}
#include <iostream>
using namespace std;
int binary(long long Arr[],long long left,long long right,long long target)
{
    while(left<=right)
    {
        long long mid=int((left+right)/2);
        if(Arr[mid]==target)
            return mid;
        else if(Arr[mid]<target)
            left=mid+1;
        else
            right=mid-1;
    }
    return right;
}
int main()
{
    int N,M;
    long long X;
    cin>>N>>M>>X;
    long long ArrA[N+1]={0};
    long long ArrB[M+1]={0};
    int bookA=0,bookB=0;
    for (int i=1;i<=N;i++)
    {
        long long a;
        cin>>a;
        ArrA[i]=ArrA[i-1]+a;
    }
    for (int i=1;i<=M;i++)
    {
        long long b;
        cin>>b;
        ArrB[i]=ArrB[i-1]+b;
    }
    int total=0;
    for(int i=0;i<=N;i++)
    {
        long long timeB=X-ArrA[i];
        if(timeB<0)
        {
            continue;
        }
        int tempB=binary(ArrB,0,M,timeB);
        total=max(total,tempB+i);
    }
    cout<<total<<endl;
}
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int a[1000];
    int N,K,sum=0;
    cin>>N>>K;
    for(int i=0;i<N;i++)cin>>a[i];
    sort(a,a+N);
    for(int i=0;i<K;i++)sum+=a[i];
    cout<<sum<<endl;
    return 0;
}

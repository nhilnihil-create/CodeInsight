#include<iostream>
using namespace std;
#define pi 3.14159265359
int main()
{
    unsigned long int n,m,a;
    unsigned long long int sum=0;
    cin>>n>>m;
    while(m>0){
        cin>>a;
        sum+=a;
        m--;
    }
    if(sum<=n) cout<<n-sum<<endl;
    else cout<<"-1"<<endl;
    return 0;
}

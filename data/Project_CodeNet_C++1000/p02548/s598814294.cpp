#include <iostream>
#include <cstring>
using namespace std;
int a[1000][2];
bool st[1000];
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;++i){
        sum+=(n-1)/i;
    }
    cout<<sum<<endl;
}
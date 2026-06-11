#include <iostream>
using namespace std;


int main()
{
int n ,a[100],c=0;cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){if(a[i]%2==1&&i%2==1){c++;}}
cout <<c;
return 0;
}

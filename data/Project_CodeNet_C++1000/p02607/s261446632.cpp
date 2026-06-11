#include <iostream>

using namespace std;

int main()
{
    int n;cin>>n;int a[n];int cnt=0;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            if (a[i]%2!=0 &i%2!=0)cnt++;
    }

    
        
    cout<<cnt;
    return 0;
}

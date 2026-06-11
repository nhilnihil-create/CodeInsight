#include <iostream>
using namespace std;
int odd(int n,int a[])
{
    int ans=0;
    for (int i = 1; i <=n ; ++i) {
        if((i%2!=0)&&(a[i-1]%2!=0))ans++;
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i <n ; ++i) {
        cin>>a[i];
    }
    cout<<odd(n,a)<<endl;
}

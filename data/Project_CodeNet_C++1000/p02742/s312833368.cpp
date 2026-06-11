#include <bits/stdc++.h>
using namespace std;
#define ref(i,n) for(int i =0;i<n;i++)

int main()
{
    long r,c;
    cin>>r>>c;
    if(r == 1 || c == 1)
        cout<<1<<"\n";
    else cout<<(r*c+1)/2<<endl;
    return 0;
}
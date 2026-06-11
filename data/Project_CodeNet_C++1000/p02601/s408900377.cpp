#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    for( int i=0; i<k; i++)
    {
        if(x>=y)
        y=y*2;
        else if(y>=z)
        z=z*2;
        else 
z=z*2;
    }
    if(x<y && y<z)
    cout<<"Yes"<<"\n";
    else
    cout<<"No\n";
    return 0;
}


#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0; i<10000; i++)
    {
        if((int)(i*.08)==n && (int)(i*.1)==k){
            cout<<i;
        return 0;
        }
    }
    cout<<-1;

}

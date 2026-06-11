#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int x,n,i=0,j,c=0,p,h[1000010];
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> h[i]; 
    }
    if(n==1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    for(i=0;i<n-1;i++)
    {
        if(h[i+1]<h[i])
        {
            h[i]-=1;
        }
        else if(h[i+1]==h[i] && h[i]-1>=h[i-1])
        {
            h[i]-=1;
        }
    }
    for(i=0;i<n-1;i++)
    {
        if(h[i]>h[i+1])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;

}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  n,c=0;
    long long t,temp=0;
    cin >> n;
    while(n--)
    {
        cin >> t;
        if(temp>t) {
            c=c+abs(temp-t);
            t=t+abs(temp-t);
        }
        temp=t;
        //cout << temp << " " << endl;
    }
    cout << c << endl;
}

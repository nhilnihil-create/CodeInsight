#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,i=0,j,c=0,p,h[1000010];
    cin >> n;
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            if(n==i*j)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;

}

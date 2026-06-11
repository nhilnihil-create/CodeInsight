#include <bits/stdc++.h>
using namespace std;
int main(void){
    int m,i=0,j,c=0,n,d[100010];
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> d[i];
    }
    sort(d,d+n);
    cout << d[n/2]-d[n/2-1] << endl;
                                    
    return 0;

}

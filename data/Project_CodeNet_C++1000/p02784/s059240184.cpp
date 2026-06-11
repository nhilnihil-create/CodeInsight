#include <bits/stdc++.h>
using namespace std;
int main(void){
    int h,n,a[100000],i;
    cin >> h >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        h=h-a[i];
    }
    if(h<=0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    

    return 0;

}

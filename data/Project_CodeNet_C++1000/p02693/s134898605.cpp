#include <bits/stdc++.h>
using namespace std;
int main(void){
    int h,w,i=0,j,c=0,k,a,b;
    cin >> k >> a >> b;
    while(1)
    {
        i++;
        if(a<=k*i && b>=k*i)
        {
            cout << "OK" << endl;
            return 0;
        }
       if(k*i>1000)
       {
           break;
       }
    }
    cout << "NG" << endl;

    return 0;

}

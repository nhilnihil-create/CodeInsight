#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a,b,i=1,j;
    cin >> a >> b;
    while(1)
    {
        if(floor (i*0.08)==a && floor (i*0.1)==b)
        {
            cout << i << endl;
            return 0;
        }
        if(i>b*20)
        {
            cout << "-1" << endl;
            return 0;
        }
        i++;
           
    }
    return 0;

}

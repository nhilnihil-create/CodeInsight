#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int h,c=1,x=0,v=0,i,p=0;
    cin >> h;
    if(h==1)
    {
        cout << "1" << endl;
        return 0;
    }
    while(1)
    {
        h=h/2;
        c=c*2;
        p+=c/2;
        
        if(h==1)
        {
            break;
        }
    }
    p=c+p;

    cout << p << endl;


    return 0;

}

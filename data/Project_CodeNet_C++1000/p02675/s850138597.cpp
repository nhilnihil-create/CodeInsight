#include <bits/stdc++.h>
using namespace std;
int main(void){
    int h,w,i=0,j,c=0,n;
    cin >> n;
    h=n;
    while(h>=10)
    {
        h=h%10;
    }
    if(h==2 || h==4 || h==5 || h==7 || h==9)
    {
        cout << "hon" << endl;
    }
    if(h==0 || h==1 || h==6 || h==8)
    {
        cout << "pon" << endl;
    }
    if(h==3)
    {
        cout << "bon" << endl;
    }
    return 0;

}

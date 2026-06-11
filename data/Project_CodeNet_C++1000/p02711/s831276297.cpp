#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,res=0;
    scanf("%d",&n);
    while(1)
    {
    res=n%10;
    if(res-7==0){
        cout << "Yes" << "\n";
        break;
    }
    n=n/10;
    res=n%10;
    if(res-7==0){
        cout << "Yes" << "\n";
        break;
    }
    n=n/10;
    res=n%10;
    if(res-7==0){
        cout << "Yes" << "\n";
        break;
    }
        else{
        cout << "No" << "\n";
        return 0;
        }
    }
    return 0;
}

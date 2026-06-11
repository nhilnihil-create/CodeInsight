#include<bits/stdc++.h>
using namespace std;
int main()
{
    int th,ts,xh,xs;
    cin>>th>>ts>>xh>>xs;
    while(1){
           xh-=ts; 
        
        if(xh<=0) break;
        th-=xs;
        if(th<=0)break;
    }
    if(th>=xh) puts("Yes");
    else puts("No");
}

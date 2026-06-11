#include <bits/stdc++.h>
#include <valarray>
using namespace std;
int main()
{
    int num;
    while(cin>>num)
    {
        if(num==0)
            break;
        double a[num];
        double sum=0,STD=0;
        for(int i=0;i<num;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        for(int i=0;i<num;i++){
            STD+=(a[i]-sum/num)*(a[i]-sum/num)/num;
        }
        cout<<setiosflags(ios::fixed)<<setprecision(10)<<sqrt(STD)<<endl;
    }
    return 0;
}

#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main()
{
    int n;
    int score[1001];

    while(cin>>n&&n)
    {
        double average=0;
        for(int i=0;i<n;i++)
        {
            cin>>score[i];
            average+=score[i];
        }
        average/=n;
        double ans=0;

        for(int i=0;i<n;i++)
        {
            ans+=(score[i]-average)*(score[i]-average);
        }
        ans=sqrt(ans/n);
        cout<<fixed<<setprecision(5)<<ans<<endl;
    }
}


#include <iostream>
using namespace std;

int main() {
    int n,w[1000],sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
        sum +=w[i];
    }
    int m=10000000,tsum=0;
    for(int i=0;i<n;i++)
    {
        tsum +=w[i];
        sum = sum-w[i];
        int d = abs(sum-tsum);
        if(m>d)
        {
            m = d;
        }
    }
    cout<<m<<endl;
}

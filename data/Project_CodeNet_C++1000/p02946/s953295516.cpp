#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int K,X,i;
    cin>>K>>X;
    X=X-(K-1);
    cout<<X<<" ";
    for(i=1;i<=(2*(K-1));i++)
    {
        X++;
        cout<<X<<" ";
    }
    return 0;
}

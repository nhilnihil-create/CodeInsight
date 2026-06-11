#include<iostream>
using namespace std;
int main()
{
    long long int n ,t ,time,sum=0;
    cin >> n >> t;
    while(t--)
    {
        cin >> time;
        sum=sum+time;
    }
    n=n-sum;
    if(n<0)
        n=-1;
    cout << n <<endl;
    return 0;
}

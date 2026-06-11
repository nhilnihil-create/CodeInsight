#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
    long long int n,y,z,temp,i;
    long double x;
    stack <int> s;
    cin>>n;
    temp=1;
    while(n>0)
    {
        n--;
        s.push(n%26);
        n/=26;
    }
    while(!s.empty())
    {
        cout<<char(s.top()+'a');
        s.pop();

    }
    cout<<"\n";
}

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%2==0)
    {
       printf("%.7f",(double)(n/2)/n);
    }
    else
    {
         printf("%.7f",(double)(n/2+1)/n);
    }
    return 0;
}

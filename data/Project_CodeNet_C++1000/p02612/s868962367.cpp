#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    for(i=0; i<10000; i++)
    {
        if(i*1000>=n)
            break;
    }
    cout<<(i*1000)-n<<endl;

}


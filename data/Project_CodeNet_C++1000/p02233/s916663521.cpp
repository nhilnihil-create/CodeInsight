#include<iostream>
using namespace std;
#define n 44
int F[n],Fl[n];
int fibonacci(int na)
{
    if( na == 1 || na == 2)
        return F[na] = 1;
    if(F[na])
        return F[na];
    return F[na] = fibonacci(na - 1) +fibonacci(na - 2 ) ;
}

void makeFibonacci()
{
    Fl[1] = Fl[0] = 1;
    for(int i=2;i<=n;i++)
    {
        Fl[i] = Fl[i-1] + Fl[i-2];
    }
}

int main()
{
    int na;
    cin>>na;
    //cout<<fibonacci(na)%10007<<endl;
    makeFibonacci();
    cout<<Fl[na]<<endl;
    return 0;
}

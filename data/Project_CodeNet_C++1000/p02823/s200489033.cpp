# include <iostream>
# include <cmath>
using namespace std;

long long N;
long long A;
long long B;

int main()
{
    cin>>N>>A>>B;

    if ((B-A)%2==0)
    {
        cout<<(B-A)/2<<endl;
    }

    else 
    {
        if ((N-B)<(A-1)) //B is closer//
        {
            long long x=B-A;
            cout<<(long long)(N-B+1+((x-1)/2))<<endl;
        }
        
        else
        {
            long long y=B-A;
            cout<<(long long)(A-1+1+((y-1)/2))<<endl;
        }
    }
}
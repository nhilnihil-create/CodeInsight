#include <iostream>
using namespace std;


bool Find(int A, int B, int C, int K)
{
    if(A<B && B<C)
    {
        return(true);
    }
    if(K==0)
    {
        return(false);
    }
    return(Find(2*A, B, C, K-1) || Find(A, 2*B, C, K-1) || Find(A, B, 2*C, K-1));
}

int main()
{
    int A, B, C, K;
    cin>>A>>B>>C>>K;
    bool temp = Find(A, B, C, K);
    if(temp==true)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}

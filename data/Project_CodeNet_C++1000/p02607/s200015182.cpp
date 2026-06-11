#include <iostream>
using namespace std;
int main()
{
    //cout<<"Enter number n of squares.\n";
    int N;
    cin>>N;
    int *num = new int[N];
    //cout<<"Enter n integers separated by a space.\n";
    int counter=0;
    for (int i=1; i<=N; i++)
    {
        cin>>num[i-1];
        if (i%2 != 0 && num[i-1]%2 != 0)
            counter++;
    }
    delete num;
    cout<<counter;
    return 0;
}
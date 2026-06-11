#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,counter=0;
    cin>>N;
    vector<int> squares(N);

    for(int i=0 ; i<N ; i++)
    {
        cin>>squares[i];
        if((i+1)%2!=0 && squares[i]%2!=0)
            counter++;
    }
    cout<<counter<<endl;

    return 0;
}

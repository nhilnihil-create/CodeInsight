#include<iostream>
using namespace std;

int main()
{
    long long A,B,res=0;
  cin >> A >> B ;
    if(A%2==B%2)
    {
        res=(A+B)/2;
        cout << res<< endl;

    }
    else{
        cout << "IMPOSSIBLE"<<endl;
    }
    return 0;
}
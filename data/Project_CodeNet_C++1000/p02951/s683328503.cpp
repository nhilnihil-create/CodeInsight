#include<iostream>
using namespace std;
int main()
{
    int A,B,C,CV;

    cin>>A>>B>>C;
    if(B+C>A){
    CV=C-(A-B);
    cout<<CV<<endl;
    }
    else{
    cout<< "0";
    }
    return 0;
}

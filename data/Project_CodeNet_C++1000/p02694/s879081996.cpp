#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    unsigned long long int tar,i=0,amount=100;
    cin>>tar;
    while(amount<tar){

        amount += amount/100;
        i++;
    }
    cout<<i<<endl;
    return 0;
}

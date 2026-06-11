#include<iostream>
using namespace std;
int sum(int n);
int main()
{
    int n;
    cin>>n;
    cout<<sum(n)<<endl;
}
int sum(int n)
{
    return (n-1)/2;
}
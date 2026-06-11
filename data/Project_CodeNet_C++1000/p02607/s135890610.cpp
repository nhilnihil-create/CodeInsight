#include<iostream>
using namespace std;
#define FIO \
    freopen("input.txt","r",stdin); \
    freopen("output.txt","w",stdout);
int main()
{
    //FIO;
    int n; cin>>n;
    int i = 1; 
    int cnt=0;
    while(i <= n)
    {
        int temp; cin>>temp;
        if(i&1 && temp&1)
          cnt++;
        i++;
    }
    cout<<cnt<<endl;
}
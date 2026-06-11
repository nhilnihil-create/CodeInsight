#include<iostream>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int arr[n];
    //  int arr2[1000];
    int c=0,b=0,x;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

//    for (int i=0; i<n; i++)
//    {
//        if (arr[i]%2==0)
//        {
//            arr2[i]=arr[i];
//            b++;
//    }
//    }
//    x=b;

    for (int i=0; i<n; i++)
    {
        if (arr[i]%2==0)
        {
            b++;
            if  ( arr[i]%3==0 || arr[i]%5==0)
           c++;
        }

    }

    if (c==b)
        cout<<"APPROVED"<<endl;

     else
     cout<<"DENIED"<<endl;

    return 0;
}

#include<iostream>
using namespace std;
int main ()
{
    int a=0;
    int b=0;
    cin>>a>>b;
    int arr[b];
    int z=0;
    for(int i =0;i<b;i++)
        cin>>arr[i];


    for(int i =0;i<b;i++)
    z=z+arr[i];

    (z>=a)?cout<<"Yes":cout<<"No";
    /*int z=0;
    for (int i=1;i<100000;i++)
    {
     a=a-b;
     if(a<=0){
     cout<<i<<endl;
      break;}
    }*/
    return 0;
}

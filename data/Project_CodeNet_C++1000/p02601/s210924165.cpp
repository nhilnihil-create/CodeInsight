#include<iostream>
using namespace std;

void magic(int a,int b,int c,int k)
{
    for (int i = 0; i < k; i++)
    {
        if(a >= b)
        {
            if (b >= c)
                c*=2;
            else
                b*=2;
        }
        else  if (a < b) {
            if(b*2 < c)
                b*=2;
            else if(b*2 >= c)
                c*=2;
        }
    }
  //  cout<<a<<"  "<<b<<"  "<<c<<endl;

  if (a < b && b < c)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}

int main ( )
{
    int a,b,c,k;
    cin>>a>>b>>c;
    cin>>k;
    magic(a,b,c,k);
    return 0;
}

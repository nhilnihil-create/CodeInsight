#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x=0;
    if(n<=1000)
        x=1000;
    else if(n>1000 && n<=2000)
        x=2000;
    else if(n>2000 && n<=3000)
        x=3000;
    else if(n>3000 && n<=4000)
        x=4000;
    else if(n>4000 && n<=5000)
        x=5000;
    else if(n>5000 && n<=6000)
        x=6000;
    else if(n>6000 && n<=7000)
        x=7000;
    else if(n>7000 && n<=8000)
        x=8000;
    else if(n>8000 && n<=9000)
        x=9000;
    else if(n>9000)
    x=10000;
        cout<<x-n<<endl;
}
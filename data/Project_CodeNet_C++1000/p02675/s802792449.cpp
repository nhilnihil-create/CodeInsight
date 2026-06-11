#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin>>n;
    switch(n%10)
    {
 case 2:
 case 4:
 case 5:
 case 7:
 case 9:
     puts("hon");
    break;
    case 0:
    case 1:
    case 6:
    case 8:
    puts("pon");
     break;
    case 3:
        puts("bon");
        break;


    }
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int input,i,move_point;
    cin>>input;
    
    for(i = (int) sqrt((float) input); i>0; i--)
    {
        if(input % i == 0) break;
    }

    move_point = i + input / i - 2;
    cout<<move_point<<endl;
}
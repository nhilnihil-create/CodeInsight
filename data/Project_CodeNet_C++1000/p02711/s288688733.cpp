#include<bits/stdc++.h>

using namespace std;

int main()
{
    int number;
    cin>>number;
    int numb = number;
    int p;
    while(numb != 0)
    {
    p = numb%10;
    numb = numb/10;
    if(p==7)
    {
        cout<<"Yes";
        return 0;

    }    
    }
    cout<<"No";
}
#include<iostream>
using namespace std;

int main()
{
    int n,c=0;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
    {
        if(p[i]!=i+1)
            c++;
    }
    if(c==0||c==2)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}

//YES You can sort p in ascending order by swapping p 1 and p5

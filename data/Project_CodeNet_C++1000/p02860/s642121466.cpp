#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a, flag = 1;
    string b;

    cin>>a>>b;
    if(a%2==0)
    {
        int c= b.length()/2;
        for(int i=0; i<c; i++)
            if(b.at(i)!=b.at(i+c))
            {
                flag = 0;
                break;
            }
        if(flag==1)
            cout<< "Yes"<<endl;
        else
            cout<< "No"<<endl;
    }
    else
        cout<< "No"<<endl;
}

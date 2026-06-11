#include<iostream>
using namespace std;

int main()
{
    int h;
    int w;
    while(1)
    {
        cin>>h>>w;
        if(h==0&&w==0)break;
        for(int i=0;i<h; i++)
        {
            for(int s=0; s<w; s++)
            {
                cout<<"#";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
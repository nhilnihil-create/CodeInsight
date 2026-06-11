# include <iostream>
using namespace std;

int H, W, A, B;

int main()
{
    cin>>H>>W>>A>>B;

    for (int i=1; i<=B; i++)
    {
        for (int j=1; j<=A; j++)
        {
            cout<<0;
        }

        for (int j=1; j<=W-A; j++)
        {
            cout<<1;
        }

        cout<<endl;
    }

    for (int i=1; i<=H-B; i++)
    {
        for (int j=1; j<=A; j++)
        {
            cout<<1;
        }
        
        for (int j=1; j<=W-A; j++)
        {
            cout<<0;
        }

        cout<<endl;
    }
}
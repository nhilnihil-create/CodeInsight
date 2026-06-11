///I am Groot |*|
///19.09.2020>>03.40 PM
#include <iostream>
using namespace std;

int main()
{
    int n;

    string s;
    cin>>n;
    cin>>s;
    if(n%2==1)
    {
        cout<<"No";
    }
    else
    {
        int x[125] = {0},flag=1;
        for(int i=0; i<n; i++)
        {
            x[s[i]]++;
        }
        for(int i=97; i<123; i++)
        {
            //cout<<x[i]<<" ";
            if(x[i]%2==1)
            {
                cout<<"No";
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"Yes";
        }
    }
}

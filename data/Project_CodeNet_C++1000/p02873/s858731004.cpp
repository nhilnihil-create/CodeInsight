# include <iostream>
using namespace std;

long long numbers[500005];
long long sum=0;

string S;

int main()
{
    numbers[0]=0;

    cin>>S;

    for (int i=0; i<S.size(); i++)
    {
        if (S[i]=='<')
        {
            numbers[i+1]=numbers[i]+1;
        }
    }

    for (int i=S.size()-1; i>=0; i--)
    {
        if (S[i]=='>')
        {
            if (numbers[i]<=numbers[i+1])
            {
                numbers[i]=numbers[i+1]+1;
            }
        }
    }

    for (int i=0; i<=S.size(); i++)
    {
        sum=sum+numbers[i];
    }

    cout<<sum<<endl;
}
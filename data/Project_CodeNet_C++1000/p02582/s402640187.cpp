#include <iostream>

using namespace std;

int main()
{
    string S;
    getline(cin,S);
    int count=0;

        if(S.find("R",0)<3)
    {
        int count=1;
        int n=S.length();
        for(int i=0; i<n; i++)
        {


                if( i<n)
                {

                    if(S[i]=='R' && S[i+1]=='R')
                    {
                        count++;
                    }
                }

        }
        cout<<count;

    }
    else
    {
        cout<<count;
    }


    return 0;
}

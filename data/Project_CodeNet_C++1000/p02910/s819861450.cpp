#include<iostream>
#include<string>

using namespace std;

int main() 
{
    string S;
    cin>>S;

    bool dance=true;

    for (int i = 0; i < S.size(); i++)
    {
        char s = S.at(i);
        if(i%2==0)
        {
            if(s=='L')
            {
                dance=false;
                break;
            }
        }
        else
        {
            if(s=='R')
            {
                dance=false;
                break;
            }
        }
    }
    
    
    dance?cout<<"Yes"<<endl:cout<<"No"<<endl;
    return 0;
}

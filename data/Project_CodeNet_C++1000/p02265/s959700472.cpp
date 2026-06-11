#include<iostream>
#include<list>

using namespace std;

int main()
{

    list<int> l;

    int n;

    cin>>n;

    char s[20];
    int value;

    for(int j=0;j<n;j++)
    {
        cin>>s;

        if(s[0]=='i')
        {
            cin>>value;
            l.push_front(value);
        }else if(s[6]=='F')
        {
            l.pop_front();
        }else if(s[6]=='L')
        {
            l.pop_back();
        }else
        {
            cin>>value;
            for(list<int>::iterator ite=l.begin();ite!=l.end();ite++)
            {
                if(*ite==value)
                {
                    l.erase(ite);
                    break;

                }
            }
        }

    }

    int i=0;
    for(list<int>::iterator ite=l.begin();ite!=l.end();ite++,i++)
    {
        if(i)
        {
            cout<<" ";
        }
        cout<<*ite;
    }

    cout<<endl;

    return 0;
}


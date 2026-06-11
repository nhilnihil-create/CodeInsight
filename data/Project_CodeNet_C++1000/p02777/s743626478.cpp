#include<iostream>
using namespace std;
int main()
{
    char str[50],strr[50];
    cin>>str>>strr;
    int n,m;
    cin>>n>>m;
    char u[100];
    cin>>u;
    if(u[0]==str[0])
    {
        n--;
    }
    else
    {
        m--;
    }

    cout<<n<<" "<<m<<endl;

}

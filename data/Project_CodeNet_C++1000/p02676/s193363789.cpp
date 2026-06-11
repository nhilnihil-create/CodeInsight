#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char palabra[1000];
    int tam,lon;
    cin >>tam;
    cin >>palabra;
    lon=strlen(palabra);

    if(lon<=tam)
    {
        for(int i = 0; i < lon; i++)
        {
            cout << palabra[i];
        }
    }
    else
    {
        for(int a = 0; a < tam; a++)
        {
            cout << palabra[a];

        }
       cout <<"...";
    }
    cout << "\n";
    return 0;
}

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int studnum[n], output[n] = {0};
    for(int i = 0; i < n; i++)
    {
        cin >> studnum[i];
    }
    int index = 1;
    while(index<=n)
    {
        for(int i = 0; i < n; i++)
        {
            if(studnum[i] == index)
            {
                output[index-1] = i+1;
                cout << output[index-1] << " ";
                index++;
                break;
            }
        }
    }
    cout << endl;
}

#include <iostream>

using namespace std;

int main()
{
    int x,y,sum =0;
    cin>>x>>y;
    int arr[x];
    for(int i = 0 ; i < x ; i++)
    {
        cin>>arr[i];
    }
    for(int m = 0 ; m < y ; m++)
    {
        int mini = -1;
        bool check = true;
        int index = -1;
        for(int i = 0 ; i < x; i++)
        {
            if(arr[i] > 0 && check)
            {
                mini = arr[i];
                check = false;
                index = i;
            }
            if(arr[i] < mini && arr[i] > 0)
            {
                mini = arr[i];
                index = i;
            }
        }
        arr[index] = -1;
        sum+=mini;
    }
    cout<<sum;
    return 0;
}

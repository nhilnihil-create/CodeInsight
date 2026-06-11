#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
        if(arr[i] % 2 !=0 && (i+1)%2 != 0)
        {
            counter++;
        }
    }
    cout<<counter;

}

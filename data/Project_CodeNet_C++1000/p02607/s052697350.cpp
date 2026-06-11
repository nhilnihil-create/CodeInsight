#include <iostream>

using namespace std;
int main()
{
    int num ;
    cin >> num ;
    int arr[num+1];
    for (int i = 1 ; i <= num ; i++)
        cin >> arr[i];
    int c = 0 ;
    for (int i = 1 ; i <= num ; i++)
    {
        if (i%2==1 && arr[i]%2==1)
            c++ ;
    }
    cout<<c<<endl;
    return 0;
}

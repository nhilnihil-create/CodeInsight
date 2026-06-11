#include <iostream>

using namespace std;

int main()
{
    int n , cnt = 0 ;
    cin >> n ;
    int a[n] ;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i+=2)
    {
        if(a[i]%2 != 0)
            cnt++ ;
    }
    cout << cnt ;

    return 0;
}

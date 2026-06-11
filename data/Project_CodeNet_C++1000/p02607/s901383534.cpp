#include <iostream>

using namespace std;

int main()
{
    int n ,j=1 ,c=0 ;
    cin >> n ;
    int a[n];
    for(int i=0 ; i<n ;i++){
        cin>> a[i] ;
        if(a[i]%2!=0 && j%2!=0)
            c=c+1 ;
        j=j+1 ;

    }
    cout<< c << endl ;
    return 0;
}

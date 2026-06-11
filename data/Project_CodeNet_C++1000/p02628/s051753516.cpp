#include <iostream>

using namespace std;

int main()
{
    int n , t ,r ,mini ,total=0 ;
    cin>> n >> t ;
    int a[n] ;
    for(int i=0 ; i<n ; i++){
        cin >> a[i] ;
    }
    for(int i=0 ; i<=n ;i++){
           for(int f=0 ; f<n-1 ;f++){
            if (a[f]>a[f+1]){
                mini = a[f] ;
                a[f]=a[f+1];
                a[f+1]=mini ;

        }
           }
    }
    for(int i=0 ; i<t ;i++){
        total+=a[i];
    }
    cout<< total << endl;
    return 0;
}
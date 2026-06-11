#include <iostream>

using namespace std;
int main ()
{
    /*/
    int i = 0, j = 1;
    cout << i;
    int *ptr = &i;
    cout << i;

    i = 2;
    cout << i;
    *ptr = 3;
    ptr = &j;
    j = i;
    cout << i;
    *ptr = 4;
      /*/
    
    int n , ctn=0 ,arr;
    cin >> n ;
    for (int i = 1; i <=n ; ++i) {
        cin >> arr;
        
        if ((i%2!=0)&&(arr%2!=0))ctn++;
       
    }
    cout<<ctn <<endl;
    

}
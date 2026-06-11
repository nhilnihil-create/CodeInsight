#include<iostream>

using namespace std ;

int main()

{
    int n, count=0;

    cin>>n ;

    for(int i=1 ; i<=n ; i=i+2)
    {
        count++ ;
    }

    cout<<(double)count/n<<endl ;

    return 0;
}
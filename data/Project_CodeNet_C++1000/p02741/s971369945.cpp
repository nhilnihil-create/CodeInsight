#include<iostream>

using namespace std;
int main()
{
    int n,a[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    cin>>n;
    for(int i=1;i<=32;i+=1){
        if(i==n){
            cout<<a[i-1]<<endl;
        }
    }


    return 0;
}

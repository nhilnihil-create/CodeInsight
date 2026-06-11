#include <iostream>

using namespace std;
int arr[101];
int main()
{
    int n=0,cou=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
 for(int i=0;i<n;i++){
        if((i%2==0)&&(arr[i]%2!=0)){
            cou++;
        }
    } cout<<cou;
    return 0;
}

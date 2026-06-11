#include <iostream>

using namespace std;

int main()
{
int n,c=0;
cin>>n;
int arr[n];
for(int i=1;i<=n;i++){
    cin>>arr[i];
    if(i%2==1&&arr[i]%2==1){
        c++;
    }
}
cout<<c;
    return 0;
}

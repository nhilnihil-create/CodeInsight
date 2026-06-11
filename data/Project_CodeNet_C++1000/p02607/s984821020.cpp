#include <iostream>

using namespace std;

int main()
{
    int n, c=0;

    cin>>n;

    int a[n];
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int j=1; j<=n; j++){
        if(j%2 != 0 && a[j]%2 != 0){
            c++;
        }
    }
    cout<<c;
    return 0;
}

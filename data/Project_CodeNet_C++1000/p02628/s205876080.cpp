#include <iostream>

using namespace std;

int main()
{
    int n,k;
    
    cin>>n;
    
    cin>>k;
    
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    // Sort
    int temp = 0, x=0;
    for(int j=1; j<n; j++){
        x=j-1;
        temp=a[j];
        while(temp < a[x] && x >= 0){
            a[x+1] = a[x];
            --x;
        }
        a[x+1] = temp;
    }
    int sum = 0;
    for(int y=0; y<k; y++){
        sum += a[y];
    }
    cout<<sum;
    return 0;
}

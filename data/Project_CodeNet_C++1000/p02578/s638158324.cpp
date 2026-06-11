#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    long int sum = 0;
    long int before = 0;

    cin>>before;

    for(int i=0; i<n-1; i++){
        long int a;
        cin>>a;
        
        if(before > a)
            sum += before - a;
        else
        {
            before = a;
        }
        
    }

    cout<<sum<<endl;

    return 0;
}
#include<iostream>
#include<algorithm>
#include<cmath>
//#include<string>
//#include<set>
//#include<vector>
//#include<iomanip>
using namespace std;
int main(){

    int n;
    cin>>n;
    int arr[n],x;
    for(int i=1;i<=n;i++){
        cin>>x;
        arr[x-1]=i;
    }
    cout<<arr[0];
    for(int i=1;i<n;i++){
        cout<<" "<<arr[i];
    }
    return 0;
}

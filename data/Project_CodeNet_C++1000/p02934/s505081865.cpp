#include <iostream>
using namespace std;
int main(void){
    int n,i;
    double x,ans=0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> x;
        ans+=1/x;
    }
    cout << 1/ans << endl;
}
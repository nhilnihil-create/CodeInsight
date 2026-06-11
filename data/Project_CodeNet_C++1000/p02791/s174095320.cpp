#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin >> n;
    int mi=n+1,count=0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        mi=min(mi,x);
        if(mi>=x) count++;
    }
    cout << count << endl;
}
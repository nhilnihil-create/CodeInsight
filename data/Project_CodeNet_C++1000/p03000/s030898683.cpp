#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,x,l;
    cin >> n >> x;
    int d[n+1];
    d[0]=0;
    for(int i=0;i<n;i++){
        cin >> l;
        d[i+1]=d[i]+l;
    }
    int count=0;
    for(int i=0;i<n+1;i++){
        if(d[i]<=x){
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}

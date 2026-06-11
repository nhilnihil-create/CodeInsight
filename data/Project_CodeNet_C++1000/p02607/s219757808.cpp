#include <iostream>
using namespace std;
int main() {
    int x,sum=0;
    cin>>x;
    int a[x];
    for (int i = 1; i <=x ; ++i) {
        cin>>a[i];
    }for (int j = 1; j <=x ; ++j) {
        if(j%2!=0&&a[j]%2!=0)
            sum++;
    }cout<<sum;
}
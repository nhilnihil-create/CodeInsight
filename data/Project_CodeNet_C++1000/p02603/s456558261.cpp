#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    int a[N+100];
    for (int i=0;i<N;i++){
        cin>>a[i];
    }
    long long money=1000;
    for (int i=0;i<N-1;i++){
        if (a[i]<a[i+1]){
            money=a[i+1]*(money/a[i])+money%a[i];
        }
    }
    cout<<money<<endl;
    return 0;
}
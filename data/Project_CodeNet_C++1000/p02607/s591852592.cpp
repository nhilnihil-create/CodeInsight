#include<bits/stdc++.h>

using namespace std;

int main() {
int n,count=0;
cin>>n;
    for (int i = 1; i <=n ; ++i) {
        int x;
        cin>>x;
        if(x%2!=0&i%2!=0)
            count++;
    }
    cout<<count;
}



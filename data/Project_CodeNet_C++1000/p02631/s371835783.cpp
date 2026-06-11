#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);

    long long Xor = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        if(i%2){
            Xor ^= (a[i]^a[i - 1]);
        }
    }

    for(int i = 0;i < n;i++)cout<<(Xor^a[i])<<" ";
    cout<<endl;
}
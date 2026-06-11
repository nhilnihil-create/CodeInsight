#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    long long n;
    cin>>n;

    vector<long long> arr;
    vector<long long> count(n+1);

    for(int i=0;i<n;i++) {
        long long num;
        cin>>num;

        arr.push_back(num);
        count[num]++;
    }

    long long total=0;
    for(int i=1;i<=n;i++) {
        if(count[i]!=0) {
            total+=(count[i]*(count[i]-1))/2;
        }
    }

    for(int i=0;i<n;i++) {
        if(arr[i]!=0) {
            cout<<total-(count[arr[i]]-1)<<endl;
        }
    }





    
}

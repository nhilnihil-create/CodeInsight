#include<bits/stdc++.h> 
using namespace std;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    int x,n;
    cin>>x>>n;

    if(n==0) {
        cout<<x<<endl;
        return 0;
    }

    vector<int> arr;
    while(n--) {
        int num;
        cin>>num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    //for(int i=0;i<arr.size();i++) {
    //    cout<<arr[i]<<' ';
    //}

    vector<int> rng={-1,1};

    for(int i=0;i<=x;i++) {
        for(int j=0;j<2;j++) {
            if(count(arr.begin(), arr.end(), x+(i*rng[j]))==0) {
                cout<<x+(i*rng[j])<<endl;
                return 0;
            }
        }

    }

}



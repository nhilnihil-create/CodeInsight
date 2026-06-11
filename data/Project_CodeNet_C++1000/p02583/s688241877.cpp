#include<bits/stdc++.h> 
using namespace std;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int t;
    cin>>t;

    vector<int> arr;
    while(t--) {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());

    int ans=0;

    cout<<endl;

    for(int i=0;i<arr.size();i++) {
        for(int j=0;j<arr.size();j++) {
            for(int x=0;x<arr.size();x++) {
                if(arr[i]<arr[j] && arr[j]<arr[x] && (arr[i]+arr[j])>arr[x]) {
                    //cout<<arr[i]<<' '<<arr[j]<<' '<<arr[x]<<endl;
                    ans++;

                }
            }
        }
    }

    cout<<ans<<endl;

}



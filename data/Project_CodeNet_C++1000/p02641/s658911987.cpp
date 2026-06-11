#include <bits/stdc++.h>
using namespace std;

int arr[105],freq[105];

int main() {
    int x ,n,element;
    cin>>x>>n;


    for(int i=0;i<n;i++){
        cin>>element;
        freq[element]++;
    }

    if(freq[x]==0){
        cout<<x<<endl;
        return 0;
    }



    for(int i=0,j=0;i<=101;i++){
        if(freq[i]==0){
            arr[j]=i;
            j++;
        }
    }

    /*int i=x;

    while(true){
        if(freq[i]==0){
            maxi = i;
            break;
        }
        i++;
    }

    int j = x;

    while(true){
        if(i<0){
            mini = i;
            break;
        }
        if(freq[i]==0){
            mini = i;
            break;
        }
        i--;
    }
    */
    sort(arr,arr+105);


    int low = *lower_bound(arr,arr+105,x);

    int mini = low-x;
    int ans = low;
    for(int i=0;i<x;i++){
        if(freq[i]==0){
            if(x-i<=mini){
                ans=i;
            }
        }
    }

    cout<<ans<<endl;


    return 0;
}

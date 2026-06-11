#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
int arr[102],freq[102];
 
int main() {
    int x ,n,element;
    cin>>x>>n;
 
 
    for(int i=0;i<n;i++){
        cin>>element;
        freq[element]++;
    }
 
 
    int j=0;
 
    for(int i=0;i<=101;i++){
        if(freq[i]==0){
            arr[j]=i;
            j++;
        }
    }
 
 
    sort(arr,arr+102);
 
 
    int low = *lower_bound(arr,arr+102,x);
 
    int mini = low-x;
    int ans = low;
 
    for(int i=0;i<=x;i++){
        if(freq[i]==0){
            if(x-i<=mini){
                ans=i;
            }
        }
    }
 
    cout<<ans<<endl;
 
 
    return 0;
}
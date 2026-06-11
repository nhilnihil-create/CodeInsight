#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll N[200100];
ll preSumN[200100];
ll M[200100];
ll preSumM[200100];
int binarySearch(ll arr[],int low,int high,ll target){
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]>target)
            high = mid-1;
        else
            low = mid+1;
    }
    return low;
}
int main(){
    int n,m,i;
    ll k,other;
    cin>>n>>m>>k;
    for(i=0;i<n;i++){
        cin>>N[i];
    }
    for(i=0;i<m;i++){
        cin>>M[i];
    }
    for(i=0;i<n;i++)
        preSumN[i+1] = preSumN[i]+N[i];
    for(i=0;i<m;i++)
        preSumM[i+1] = preSumM[i]+M[i];
    int total=0;
    for(i=0;i<=n;i++){
        other = k-preSumN[i];
        if(other < 0)
            continue;
        int j = binarySearch(preSumM,0,m,other);
        if(preSumM[j] > other || j > m)
            j--;
        total = max(total,i+j);
    }
    cout<<total;
    return 0;
}

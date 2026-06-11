#include <bits/stdc++.h>
using namespace std;
int Bsearch(int p[],int x,int n){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid = (low + high)/2;
        if(p[mid]==x)
            return mid;
        else if(p[mid]>x)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}
int check(int find,int p[],int n){
    int k=find;
    while(true){
    k=k-1;
    if(k==0)
        return 0;
    int index = Bsearch(p,k,n);
    if(index==-1)
        return k;
    find+=1;
    index = Bsearch(p,find,n);
    if(index==-1)
        return find;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,n;
    cin >> x >> n;
    int p[n];
    for(int i=0;i<n;i++)
        cin >> p[i];
    sort(p,p+n);
    int find = x;
    if(Bsearch(p,find,n)==-1)
        cout << find;
    else{
    int ans = check(find,p,n);
    cout << ans ;}
    return 0;
}
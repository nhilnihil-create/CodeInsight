#include <bits/stdc++.h>

using namespace std;


int main() {

   int n,m;
   cin>>n>>m;
   const int N = n*2 -1;
   int arr[N];
   arr[0]=m;
   int j=1;

   for(int i=m+1;i<m+n;i++){
       arr[j++]=i;
   }

    for(int i=m-1;i>m-n;i--){
        arr[j++]=i;
    }


    sort(arr,arr+j);

    for(int i=0;i<j;i++)cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}

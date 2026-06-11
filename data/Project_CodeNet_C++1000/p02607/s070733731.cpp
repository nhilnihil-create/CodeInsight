#include <bits/stdc++.h>
using namespace std;
int main()
{
int n=0;cin>>n;
int arr[n]; for (int i =0 ; i<n ; i++){cin>>arr[i];}
int counter=0;
for (int i =0 ; i<n ; i=i+2){if(arr[i]%2!=0){counter++;}}
cout<<counter;
}
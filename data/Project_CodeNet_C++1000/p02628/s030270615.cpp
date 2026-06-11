#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
int N,K;
cin>>N>>K;
int arr[1100];
for(int i=0;i<N;++i)
{
    cin>>arr[i];
}
sort(arr,arr+N);

int counter=0;
for(int i=0;i<K;++i)
{

    counter+=arr[i];
}
cout<<counter;
    return 0;
}

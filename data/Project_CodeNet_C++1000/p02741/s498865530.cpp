#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int arr[100]={1,1,1,2,1,2,1,5,2,2,1,5,1,2,1,14,1,5,1,5,2,2,1,15,2,2,5,4,1,4,1,51};
    int k;
    scanf("%d",&k);
    printf("%d",arr[k-1]);
    return 0;
}

